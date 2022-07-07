/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:38:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 01:24:39 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envi(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		printf("%s\n", temp->line);
		temp = temp->next;
	}
	return (0);
}
