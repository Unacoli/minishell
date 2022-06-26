/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/26 18:28:52 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_ast(t_ast *ast)
{
    if (ast->left && ast->right)
    {
        printf("left: %d, node: %d, right: %d\n",
            (int)ast->type, (int)ast->left->type, (int)ast->right->type);
        print_ast(ast->left);
        print_ast(ast->right);
    }
    else if (ast->left)
    {
        printf("left: %d, node: %d, right: NULL\n",
            (int)ast->type, (int)ast->left->type);
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

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
	{
		print_ast(minishell->ast);
	}
	//exit_free(minishell);
}
