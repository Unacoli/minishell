/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_substi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/05 15:18:39 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 	Alloue une chaine de charactere et copie la quantite d'input que l'on veut
	Ajoute le token au lexer
	Decale input a la nouvel position */

static void	create_str_add_token_word(int *i, char **input)
{
	char	*str;

	str = create_str(*input, *i);
	add_token_to_lexer(lexer, str, *i, TOKEN_WORD);
	*input = *input + *i;
}

/* 	On ne doit pas faire les substitution de commande et arithmetique 
	mais je choisis	d'accepter les () et {} -> si on les prends pas on
	peut avoir '$' tout seul ou alors on met un message d'erreur a ce 
	moment la ? + cas ou les parentheses sont pas fermes */

static int	delimite_substitution(char *inp)
{
	int	i;

	i = 1;
	while (inp[i] && (ft_isalphanum(inp[i]) || inp[i] == '_' || inp[i] == ')' \
	|| inp[i] == '(' || inp[i] == '{' || inp[i] == '}'))
		(i)++;
	return (i);
}

/* 	Delimite le token precedant le '$' et l'ajoute au lexer
	Delimite la subistitution et l'ajoute au lexer
	Input et i sont ajuste pour correspondre a la nouvelle position */

static void	handle_substi_quote(int *i, char **input, t_lexer *lexer)
{
	char	*inp;

	inp = *input;
	create_str_add_token_word(i, input);
	inp = *input;
	*i = delimite_substitution(inp);
	create_str_add_token_word(i, input);
	*i = 0;
}

/*	Parcour tout l'input jusqu'a la quote correspondante 
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
			exit (0); //free lexer + tokens
		}
	}
	str = (char *) malloc(sizeof(char) * (i + 3));
	ft_strlcpy(str, input, i + 2);
	return ((t_regex){str, i + 1, TOKEN_WORD});
}

t_regex	handle_substitution(char *input, t_lexer *lexer)
{
	int		i;
	char	*str;

	i = delimite_substitution(input);
	str = create_str(input, i);
	return ((t_regex){str, i, TOKEN_WORD});
}
