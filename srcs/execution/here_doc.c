/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:24:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/09 11:14:40 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Dans le cas ou on a un token DLESS, on envoie le mot qui suit a here_doc
	Here_doc renvoit le fd du pipe dans lequel il a envoye les informations */

char	*get_line(char *line, int *pip)
{
	ft_putstr_fd(line, pip[1]);
	// ft_putstr_fd("\n", pip[1]);
	free(line);
	line = readline("heredoc> ");
	if (line == NULL)
		printf("here-document delimited by end-of-file\n");
	line = ft_strjoin_free1(line, "\n");
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
		perror("Pipe");
		return (-1);
	}
	fd = pip[0];
	line = NULL;
	line = readline("heredoc> ");
	if (line == NULL)
		printf("warning: here-document delimited by end-of-file\n");
	line = ft_strjoin_free1(line, "\n");
	while (line != NULL && ft_strncmp(line, delimiter, ft_strlen(line)) != 0)
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

int d_less(t_cmd *cmd, t_ctrl *minishell, int pos, int lexer_size)
{
	if (pos + 1 < lexer_size && minishell->lexer->tokens[pos + 1]->type == TOKEN_WORD)
	{
		cmd->input_file = here_doc(ft_strjoin_free1(minishell->lexer->tokens[pos + 1]->str, "\n"), minishell->env);
		if (cmd->input_file >= 0)
			return (0);
		else
			return (1);
	}
	else
	{
		printf("Syntax error near token DLESS\n");
		return  (1);
	}
	return (1);
}
