/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/05 05:32:42 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_ast(t_ast *ast)
{
    if (ast->left && ast->right)
    {
        printf("left: %d, node: %d, right: %d\n",
            (int)ast->left->type, (int)ast->type, (int)ast->right->type);
        print_ast(ast->left);
        print_ast(ast->right);
    }
    else if (ast->left)
    {
        printf("left: %d, node: %d, right: NULL\n",
            (int)ast->left->type, (int)ast->type);
        print_ast(ast->left);
    }
   else if (ast->right)
    {
        printf("left: NULL, node: %d, right: %d\n",
            (int)ast->type, (int)ast->right->type);
        print_ast(ast->right);
    }
    else
    {
        printf("left: NULL, node: %d, right: NULL\n", (int)ast->type);
    }
}

int		ft_execution(t_lexer *lexer)
{
	t_token	token;

	while (lexer->pos < lexer->size)
	{
		token = lexer->tokens[lexer->pos];
		if (token == TOKEN_WORD)
			lexer->pos = exec_cmd();
		else if (token == TOKEN_LESS)
			lexer->pos = ;
		else if (token == TOKEN_GREAT)
			lexer->pos = ;
		else if (token == TOKEN_DGREAT)
			lexer->pos = ;
		else if (token == TOKEN_DLESS)
			lexer->pos = ;
		else if (token == TOKEN_PIPE && lexer->pos == 0)
			return (printf("Parse error near '|'\n");
		lexer->pos++;
	}
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	while (cmd != -1)
		ft_execution(minishell->lexer);
	exit_free(minishell);
}
