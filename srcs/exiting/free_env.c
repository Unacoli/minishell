/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:57:13 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/03 11:41:05 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env *env)
{
	t_env	*temp;

	if (env)
	{
		while (env)
		{
			if (env->line)
				free(env->line);
			temp = env;
			env = env->next;
			if (temp)
				free(temp);
		}
	}
}
