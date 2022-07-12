/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:19:52 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/12 11:28:33 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_3_str(char *before, char *substi, char *after)
{
	char	*str;

	str = ft_strjoin_free2(before, substi);
	str = ft_strjoin_free2(str, after);
	return (str);
}

char	*make_3_str(char *str, int position, int j, char *value)
{
	char	*before_substi;
	char	*substi;
	char	*after_substi;

	before_substi = ft_calloc(position, sizeof(char));
	substi = ft_calloc(ft_strlen(value) + 1, sizeof(char));
	after_substi = ft_calloc((ft_strlen(str) - j) + 1, sizeof(char));
	ft_strlcpy(before_substi, str, position);
	ft_strlcpy(substi, value, ft_strlen(value) + 1);
	ft_strlcpy(after_substi, str + j, (ft_strlen(str) - j) + 1);
	return (join_3_str(before_substi, substi, after_substi));
}

char	*substitution(char *str, int position, t_env *env)
{
	int		j;
	char	*variable;
	char	*value;

	j = position;
	if (str[position] == '?')
	{
		variable = ft_itoa(g_status);
		value = variable;
		j++;
	}
	else
	{
		while (str[j] && (!is_space(str[j]) && (isalnum(str[j]) \
		|| str[j] == '_')))
			j++;
		variable = ft_calloc(j - position + 1, sizeof(char));
		ft_strlcpy(variable, str + position, (j - position + 1));
		value = search_env(*env, variable);
		if (value == NULL)
			value = ft_strdup("");
	}
	return (make_3_str(str, position, j, value));
}

char	*search_substi(t_env *env, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			str = substitution(str, i + 1, env);
		else
			i++;
	}
	return (str);
}
