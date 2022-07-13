/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:49:31 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 20:42:02 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*add_pwd(void)
{
	t_env	*buf;

	buf = ft_calloc(1, sizeof(t_env));
	if (!buf)
		return (NULL);
	buf->line = get_pwd();
	buf->line = ft_strjoin_free("PWD=", buf->line);
	if (!buf->line)
		return (NULL);
	buf->next = NULL;
	return (buf);
}

t_env	*default_env(void)
{
	t_env	*env;

	env = add_pwd();
	if (env)
		env->next = NULL;
	if (!env)
		return (NULL);
	return (env);
}
