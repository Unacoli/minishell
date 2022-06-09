/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:38:49 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/09 14:39:42 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
