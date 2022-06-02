/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_substi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 10:12:52 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 	Alloue une chaine de charactere et copie la quantite d'input que l'on veut
	Ajoute le token au lexer
	Decale input a la nouvel position */

static void	create_str_add_token_word(int *i, char **input, t_lexer *lexer)
{
	char	*str;

	str = create_str(*input, *i);
	add_token_to_lexer(lexer, str, *i, TOKEN_WORD);
	*input = *input + *i;
}

/* 	Delimite le token precedant le '$' et l'ajoute au lexer
	Delimite la subistitution et l'ajoute au lexer
	Input et i sont ajuste pour correspondre a la nouvelle position */

static void	handle_substi_quote(int *i, char **input, t_lexer *lexer)
{
	char	*inp;

	inp = *input;
	create_str_add_token_word(i, input, lexer);
	inp = *input;
	*i = delimite_word(inp, 1);
	create_str_add_token_word(i, input, lexer);
	*i = 0;
}

/*	Parcours tout l'input jusqu'a la quote correspondante 
	Et le stocke dans un seul token
	Si on a la combinaison $ et "", on fragmente en plusieurs token */

t_regex	handle_quote(char *input, t_lexer *lexer, char c)
{
	int		i;
	char	*str;

	i = 1;
	while (input[i] != c)
	{
		if (input[i] == '$' && c == DOUBLE_QUOTE)
			handle_substi_quote(&i, &input, lexer);
		i++;
		if (!input[i] && input[i] != c)
		{
			printf("Quote is not closed !");
			return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
		}
	}
	str = (char *) malloc(sizeof(char) * (i + 3));
	if (str == NULL)
		return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
	ft_strlcpy(str, input, i + 2);
	return ((t_regex){str, i + 1, TOKEN_WORD});
}

t_regex	handle_substitution(char *input)
{
	int		i;
	char	*str;

	i = delimite_word(input, 1);
	str = create_str(input, i);
	if (str == NULL)
		return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
	return ((t_regex){str, i, TOKEN_WORD});
}
