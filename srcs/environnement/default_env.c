/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:49:31 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 09:53:26 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*add_pwd(t_env *next_elem)
{
	t_env	*buf;

	buf = ft_calloc(1, sizeof(t_env));
	buf->line = get_pwd();
	buf->line = ft_strjoin_free("PWD=", buf->line);
	buf->next = next_elem;
	return (buf);
}

static t_env	*add_old_pwd(char *pwd, t_env *next_elem)
{
	t_env	*buf;
	int		diff;
	char	*temp;

	buf = ft_calloc(1, sizeof(t_env));
	diff = ft_strrchr(pwd, '/') - pwd;
	temp = (char *) malloc(sizeof(char) * (diff + 1));
	ft_strlcpy(temp, pwd, diff + 1);
	buf->line = ft_strjoin_free("OLD_PWD=", temp + 4);
	buf->next = next_elem;
	return (buf);
}

t_env	*default_env(void)
{
	t_env	*env;

	env = add_pwd(NULL);
	env->next = add_old_pwd(env->line, NULL);
	return (env);
}
