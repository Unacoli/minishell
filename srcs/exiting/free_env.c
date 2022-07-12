/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:57:13 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/12 21:17:32 by nargouse         ###   ########.fr       */
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
			temp = env->next;
			if (env->line)
				free(env->line);
			free(env);
			env = temp;
		}
	}
}
