/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:28:42 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/12 18:32:56 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* S'il y a eu une erreur, un token non valide ou une str NULL
	ont ete ajoute a tokens, on parcoure alors le lexer pour verifier
	qu'aucune erreur ne c'est produite pendant la tokenisation */

static void	free_list(t_token *rlist)
{
	int	i;

	i = 0;
	if (rlist)
	{
		while (i < 12)
		{
			if (rlist[i].str)
				free(rlist[i].str);
			i++;
		}
		free(rlist);
	}
}

static t_token	*create_rlist(t_token *rlist)
{
	rlist = malloc(sizeof(t_token) * 12);
	if (!rlist)
		return (NULL);
	rlist[0] = create_token(">>", 2, TOKEN_DGREAT);
	rlist[1] = create_token("<<", 2, TOKEN_DLESS);
	rlist[2] = create_token("\n", 1, TOKEN_NEWLINE);
	rlist[3] = create_token("|", 1, TOKEN_PIPE);
	rlist[4] = create_token(">", 1, TOKEN_GREAT);
	rlist[5] = create_token("<", 1, TOKEN_LESS);
	rlist[6] = create_token(" ", 1, TOKEN_PASS);
	rlist[7] = create_token("\v", 1, TOKEN_PASS);
	rlist[8] = create_token("\t", 1, TOKEN_PASS);
	rlist[9] = create_token("\r", 1, TOKEN_PASS);
	rlist[10] = create_token("\f", 1, TOKEN_PASS);
	rlist[11] = create_token(NULL, 0, TOKEN_NOT_VALID);
	if (rlist->str == NULL)
		return (NULL);
	return (rlist);
}

static int	check_error(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	while (i < lexer->size)
	{
		if (lexer->tokens[i]->str == NULL)
			return (1);
		if (lexer->tokens[i]->type == TOKEN_NOT_VALID)
			return (1);
		i++;
	}
	return (0);
}

/* 	Si on repere un TOKEN_NOT_VALID,  on renvoit EXIT_FAILURE et
	il faut alors free lexer */

int	tokenize(t_lexer *lexer, t_env *env)
{
	t_token	token;
	t_token	*rlist;

	rlist = NULL;
	rlist = create_rlist(rlist);
	lexer->pos = 0;
	while (lexer->input[lexer->pos])
	{
		token = get_token(lexer->input + lexer->pos, env, rlist);
		handle_token(lexer, token);
		if (token.str)
			free((char *)token.str);
	}
	free_list(rlist);
	if (check_error(lexer) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
