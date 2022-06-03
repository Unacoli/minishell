/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:49:48 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/03 15:07:27 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	create_token(const char *str, size_t len, t_ttype type)
{
	t_token	result;

	result.len = len;
	result.type = type;
	result.str = ft_newstr(len + 1);
	if (result.str == NULL)
		return ((t_token){NULL, 0, TOKEN_NOT_VALID});
	ft_strlcpy(result.str, str, (len + 1));
	return (result);
}

t_token	*malloc_token(const char *s, size_t len, t_ttype type)
{
	t_token	*result;

	result = malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	*result = create_token(s, len, type);
	if (result->str == NULL)
		return (NULL);
	return (result);
}
