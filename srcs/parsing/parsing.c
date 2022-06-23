/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:08 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/24 00:05:11 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse(t_ast **root, t_lexer *lexer)
{
	int	parsed;

	parsed = 1;
	lexer->pos = 0;
	create_root(root);
	while ((lexer->pos < lexer->size) && parsed != 0)
		parsed = parsed_command(root, lexer);
	if (lexer->pos < lexer->size)
		return (printf("Syntax Error"));
	return (0);
}

// int	main(void)
// {
// 	size_t	i;
// 	t_lexer	*lexer;

// 	lexer = NULL;
// 	lexer = parse("cat | 'Bonjour $PATH' $PAT<H cat< scho 
// 	<< $USER \n Sam-sam\"mot\"");
// 	i = 0;
// 	printf("size = %zu\n", lexer->size);
// 	while (i < lexer->size)
// 	{
// 		printf("%s, %li, %d\n", lexer->tokens[i]->str, 
// 		lexer->tokens[i]->len, lexer->tokens[i]->type);
// 		i++;
// 	}
// }
