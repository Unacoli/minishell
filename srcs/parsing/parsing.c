/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:08 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/11 17:00:19 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	if (lexer)
	{
		if (lexer->tokens)
		{
			while (i < lexer->size)
			{
				if (lexer->tokens[i])
				{
					if (lexer->tokens[i]->str)
						free(lexer->tokens[i]->str);
					free(lexer->tokens[i]);
				}
				i++;
			}
			free(lexer->tokens);
		}	
		free(lexer);
	}
}

/* 	comment on definit la capacite ? je met 12 par defaut
	pour l'instant retour de malloc NULL, retour NULL, peut etre a modifier
	je ne sais pas quel code d'erreur mettre dans exit + printf msg ? 
	je sais pas vraiment si input doit etre free dans cette fonction
	*/
t_lexer	*parse(char *input)
{
	t_lexer	*lexer;

	lexer = malloc_lexer(12);
	lexer->input = input;
	if (lexer == NULL)
		return (NULL);
	if (tokenize(lexer) == EXIT_FAILURE)
	{
		free_lexer(lexer);
		printf("Sadly, there was a mistake : %s", strerror(errno));
		exit(0);
	}
	return (lexer);
}

// int	main(void)
// {
// 	size_t	i;
// 	t_lexer	*lexer;

// 	lexer = NULL;
// 	lexer = parse("cat | 'Bonjour $PATH' << $USER \n Sam-sam\"mot\"");
// 	i = 0;
// 	printf("size = %zu\n", lexer->size);
// 	while (i < lexer->size)
// 	{
// 		printf("%s, %li, %d\n", lexer->tokens[i]->str, 
// 		lexer->tokens[i]->len, lexer->tokens[i]->type);
// 		i++;
// 	}
// }
