/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:35:15 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/29 22:45:48 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_root(t_ast **root)
{
	*root = malloc_ast(NODE_PROGRAM, "Program");
}

t_ast	create_ast(t_node p_type, char *p_data)
{
	t_ast	result;

	result.type = p_type;
	result.left = NULL;
	result.right = NULL;
	result.data = p_data;
	return (result);
}

t_ast	*malloc_ast(t_node p_type, char *p_data)
{
	t_ast	*result = NULL;

	result = malloc(sizeof(t_ast));
	if (!result)
	{
		printf("Error malloc\n");
		exit(EXIT_FAILURE);
	}
	*result = create_ast(p_type, p_data);
	return (result);
}

void	free_ast(t_ast **to_free)
{
	if (*to_free && to_free)
	{
		free_ast(&(*to_free)->left);
		free_ast(&(*to_free)->right);
		free(*to_free);
		*to_free = NULL;
	}
}
