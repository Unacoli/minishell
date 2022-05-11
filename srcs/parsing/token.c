/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:28:42 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/11 16:58:43 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	create_token(const char *str, size_t len, t_ttype type)
{
	t_token	result;

	result.len = len;
	result.type = type;
	result.str = ft_newstr(len);
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

/* S'il y a eu une erreur, un token non valide ou une str NULL
	ont ete ajoute a tokens, on parcoure alors le lexer pour verifier
	qu'aucune erreur ne c'est produite pendant la tokenisation */

int	check_error(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	while (i < lexer-> size)
	{
		if (lexer->tokens[i]->str == NULL)
			return (1);
		if (lexer->tokens[i]-> type == TOKEN_NOT_VALID)
			return (1);
		i++;
	}
	return (0);
}

/* 	Si on repere un TOKEN_NOT_VALID,  on renvoit EXIT_FAILURE et
	il faut alors lexer */

int	tokenize(t_lexer *lexer)
{
	t_regex	token;

	lexer->pos = 0;
	while (lexer->input[lexer->pos])
	{
		token = get_token(lexer->input + lexer->pos, lexer);
		handle_token(lexer, token);
	}
	if (check_error(lexer))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
