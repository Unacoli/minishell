/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:38:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/13 14:35:20 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*envi(t_env env)
{
	t_env	*temp;

	temp = &env;
	while (temp)
	{
		printf("%s\n", temp->line);
		temp = temp->next;
	}
	return (NULL);
}
