/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:34:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/20 14:54:44 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_eof(t_ctrl *shell)
{
	ft_putchar_fd('\n', 0);
	exit_shell(shell);
}

static int	read_input(t_lexer *lexer)
{
	int	ret;

	ret = 0;
	lexer->pos = 0;
	if (lexer->input)
	{
		ret = tokenize(lexer);
		free(lexer->input);
		lexer->input = NULL;
	}
	return (ret);
}

static int	prompt(t_ctrl *shell)
{
	shell->lexer->input = readline("minishell% ");
	if (!shell->lexer->input)
		handle_eof(shell);
	return (read_input(shell->lexer));
}

int	ft_command(t_ctrl *shell)
{
	int		lines;

	lines = 0;
	shell->lexer = malloc_lexer(10);
	if (!shell->lexer)
		exit_shell(shell);
	lines = prompt(shell);
	while (lines == 1)
		lines = prompt(shell);
	if (lines == 0)
	{
		//return (parse(&(shell->ast), shell->lexer));
		return (0);
	}
	return (lines);
}
