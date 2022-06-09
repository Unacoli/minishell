/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:34:05 by nargouse          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/03 16:09:22 by ldubuche         ###   ########.fr       */
=======
/*   Updated: 2022/06/09 04:24:36 by nargouse         ###   ########.fr       */
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_eof(t_ctrl *shell)
{
<<<<<<< HEAD
	ft_putstr("\n");
=======
	ft_putchar_fd('\n', 0);
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
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
<<<<<<< HEAD
		free(lexer->input);
		lexer->input = NULL;
=======
		ft_strdel(lexer->input, ft_strlen(lexer->input) + 1);
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
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
	size_t	i;

	i = 0;
	lines = 0;
	shell->lexer = malloc_lexer(10);
	if (!shell->lexer)
		exit_shell(shell);
<<<<<<< HEAD
	lines = prompt(shell);
=======
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
	while (lines == 1)
		lines = prompt(shell);
	if (lines == 0)
	{
		//return (parse(&(shell->ast), shell->lexer));
		return (0);
	}
	return (lines);
}
