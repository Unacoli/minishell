/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:34:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/13 18:55:06 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_eof(t_ctrl *shell)
{
	ft_putchar_fd('\n', 1);
	free_lexer(shell->lexer);
	free_env(shell->env);
	exit(0);
}

static int	new_line(t_ctrl *shell)
{	
	free(shell->lexer->input);
	return (-1);
}

static int	read_input(t_lexer *lexer, t_env *env)
{
	int	ret;

	ret = 0;
	lexer->pos = 0;
	if (lexer->input)
		ret = tokenize(lexer, env);
	return (ret);
}

static int	prompt(t_ctrl *shell)
{
	int	ret;

	ret = 0;
	shell->lexer->input = NULL;
	shell->lexer->input = readline("minishell% ");
	if (!shell->lexer->input)
		handle_eof(shell);
	else if (shell->lexer->input[0] == '\0')
		return (new_line(shell));
	if (shell->lexer->input)
		ret = read_input(shell->lexer, shell->env);
	if (shell->lexer->input && *shell->lexer->input)
	{
		add_history(shell->lexer->input);
		free(shell->lexer->input);
	}
	return (ret);
}

int	ft_command(t_ctrl *shell)
{
	int		lines;

	lines = 0;
	shell->lexer = malloc_lexer(42);
	if (!shell->lexer)
		exit_free(shell);
	lines = prompt(shell);
	if (lines == 1 || !shell->lexer->tokens[0])
		return (-1);
	if (lines == 0)
		return (EXIT_SUCCESS);
	return (lines);
}
