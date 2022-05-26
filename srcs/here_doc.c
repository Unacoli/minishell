/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:24:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/24 23:43:29 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Dans le cas ou on a un token DLESS, on envoie le mot qui suit a here_doc
	Here_doc renvoit le fd du pipe dans lequel il a envoye les informations */

static  void	heredoc_ctrld(int sig)
{
	(void) sig;
	printf("here-document delimited by end-of-file\n");
	/* fermer le here_doc mais continuer l'execution*/
}
 /* Test + norminette + clean + substitution*/

char	*get_line()
{
	ft_putstr_fd("heredoc>", STDOUT_FILENO);
	line = get_next_line(STDOUT_FILENO);
	if (line == NULL)
	{
		if (pip)
			free(pip);
	}
	
}

int	here_doc(char *delimiter)
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
	ft_putstr_fd("heredoc>", STDOUT_FILENO);
	line = get_next_line(STDOUT_FILENO);
	if (line == NULL)
	{
		if (pip)
			free(pip);
	}
	while (ft_strncmp(line, delimiter, ft_strlen(line)) != 0)
	{
		ft_putstr_fd(line, pip[1]);
		free(line);
		
	}
	close(pip[1]);
	free(pip);
	return (fd);
}
