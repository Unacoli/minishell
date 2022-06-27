/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:28:42 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/27 12:02:15 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* S'il y a eu une erreur, un token non valide ou une str NULL
	ont ete ajoute a tokens, on parcoure alors le lexer pour verifier
	qu'aucune erreur ne c'est produite pendant la tokenisation */

static int	check_error(t_lexer *lexer)
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
	il faut alors free lexer */

int	tokenize(t_lexer *lexer)
{
	t_regex	token;

	lexer->pos = 0;
	while (lexer->input[lexer->pos])
	{
		token = get_token(lexer->input + lexer->pos);
		// lexer->pos += token.len;
		handle_token(lexer, token);
		if (token.str)
			free((char *)token.str);
	}
	if (check_error(lexer))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// int	main(void)
// {
// 	size_t	i;
// 	t_lexer	*lexer;

// 	lexer = NULL;
// 	lexer = malloc_lexer(10);
// 	lexer->input = "ls > cat";
// 	tokenize(lexer);
// 	i = 0;
// 	printf("size = %zu\n", lexer->size);
// 	while (i < lexer->size)
// 	{
// 		printf("%s, %li, %d\n", lexer->tokens[i]->str, 
// 		lexer->tokens[i]->len, lexer->tokens[i]->type);
// 		i++;
// 	}
// }
