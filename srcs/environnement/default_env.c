/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:49:31 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/24 12:42:19 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*add_pwd(t_env *next_elem)
{
	t_env	*buf;
	int		size;

	buf = ft_calloc(1, sizeof(t_env));
	size = 50;
	buf->line = ft_calloc(size, sizeof(char));
	while (getcwd(buf->line, size) == NULL)
	{
		size += 50;
		free(buf->line);
		buf->line = ft_calloc(size, sizeof(char));
	}
	buf->line = ft_strjoin("PWD=", buf->line);
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
	buf->line = ft_strjoin("OLD_PWD=", temp+4);
	buf->next = next_elem;
	return(buf);
}

t_env	*default_env(void)
{
	t_env	*env;

	env = add_pwd(NULL);
	env->next = add_old_pwd(env->line, NULL);
	return (env);
}
