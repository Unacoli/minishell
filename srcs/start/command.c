/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:34:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/13 17:42:50 by nargouse         ###   ########.fr       */
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
	{
		ret = tokenize(lexer, env);
		free(lexer->input);
		lexer->input = NULL;
	}
	return (ret);
}

static int	prompt(t_ctrl *shell)
{
	shell->lexer->input = NULL;
	shell->lexer->input = readline("minishell% ");
	if (!shell->lexer->input)
		handle_eof(shell);
	else if (shell->lexer->input[0] == '\0')
		return (new_line(shell));
	else if (shell->lexer->input && *shell->lexer->input)
	{
		add_history(shell->lexer->input);
		printf("after history : %s\n", shell->lexer->input);
	}
	return (read_input(shell->lexer, shell->env));
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
