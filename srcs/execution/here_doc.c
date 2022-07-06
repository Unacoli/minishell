/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:24:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/06 15:18:30 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Dans le cas ou on a un token DLESS, on envoie le mot qui suit a here_doc
	Here_doc renvoit le fd du pipe dans lequel il a envoye les informations */

char	*get_line(char *line, int *pip)
{
	ft_putstr_fd(line, pip[1]);
	ft_putstr_fd("\n", pip[1]);
	free(line);
	line = readline("heredoc> ");
	if (line == NULL)
		printf("here-document delimited by end-of-file\n");
	return (line);
}

int	here_doc(char *delimiter, t_env *env)
{
	char	*line;
	int		*pip;
	int		fd;

	pip = (int *) malloc(sizeof(int) * 2);
	if (pipe(pip) < 0)
	{
		printf("Pipe error\n");
		return (-1);
	}
	fd = pip[0];
	line = NULL;
	line = readline("heredoc> ");
	if (line == NULL)
		printf("here-document delimited by end-of-file\n");
	while (line && ft_strncmp(line, delimiter, ft_strlen(line)) != 0)
	{
		line = search_substi(env, line);
		line = get_line(line, pip);
	}
	close(pip[1]);
	free(pip);
	if (line)
		free(line);
	return (fd);
}
