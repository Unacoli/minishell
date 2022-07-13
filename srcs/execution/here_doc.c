/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:24:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 17:01:29 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Dans le cas ou on a un token DLESS, on envoie le mot qui suit a here_doc
	Here_doc renvoit le fd du pipe dans lequel il a envoye les informations */

void	delimted(int fd)
{
	printf("\nwarning : here-document delimited by end-of-file\n");
	ft_putchar_fd('\0', fd);
}

char	*get_line(char *line, int *pip, t_env *env)
{
	line = search_substi(env, line);
	ft_putstr_fd(line, pip[1]);
	free(line);
	line = readline("heredoc> ");
	if (line != NULL)
		line = ft_strjoin_free1(line, "\n");
	else
		delimted(pip[1]);
	return (line);
}

int	here_doc(char *deli, t_env *env)
{
	char	*line;
	int		*pip;
	int		fd;

	pip = (int *) malloc(sizeof(int) * 2);
	if (pipe(pip) < 0)
		return (-1);
	fd = pip[0];
	line = readline("heredoc> ");
	if (line != NULL)
	{
		line = ft_strjoin_free1(line, "\n");
		while (line != NULL && ft_strncmp(line, deli, ft_strlen(line)) != 0)
			line = get_line(line, pip, env);
	}
	else
		delimted(pip[1]);
	close(pip[1]);
	free(pip);
	free(deli);
	if (line)
		free(line);
	return (fd);
}

int	d_less(t_cmd *cmd, t_ctrl *ms, int pos, int lexer_size)
{
	if (pos + 1 < lexer_size && ms->lexer->tokens[pos + 1]->type == TOKEN_WORD)
	{
		if (cmd->input_file > 2)
			close(cmd->input_file);
		cmd->input_file
			= here_doc(ft_strjoin(ms->lexer->tokens[pos + 1]->str, "\n"),
				ms->env);
		if (cmd->input_file >= 0)
			return (0);
		else
		{
			perror("Heredoc");
			return (1);
		}
	}
	else
	{
		printf("Syntax error near token DLESS\n");
		return (1);
	}
	return (1);
}
