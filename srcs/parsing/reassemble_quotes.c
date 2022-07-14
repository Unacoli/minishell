/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassemble_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 06:15:13 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/14 06:15:16 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quote_closed_in_another_token(t_lexer *lexer, int i)
{
	printf("quote closed dans un autre token\n");
	(void)lexer;
	(void)i;
	return ;
}

static void	quote_not_closed(t_token *token)
{
	token->type = TOKEN_NOT_VALID;
	ft_putstr_fd("Quote is not closed !\n", STDERR_FILENO);
	g_status = 1;
}

static char	*find_double_quote(t_lexer *lexer, char *chr_ouvrante, int *i)
{
	char *chr_fermante;

	while (lexer->tokens[*i] && lexer->tokens[*i]->type == TOKEN_WORD)
	{
		chr_fermante = ft_strchr(lexer->tokens[*i]->str, '"');
		if (chr_fermante != NULL)
		{
			quote_closed_in_another_token(lexer, *i);
			(*i)++;
			return (chr_fermante);
		}
		(*i)++;
	}
	quote_not_closed(lexer->tokens[*i - 1]);
	(void)chr_ouvrante;
	return (NULL);
}

void	reassemble_quotes(t_lexer *lexer)
{
	int		i;
	char	*chr_ouvrante;
	char	*chr_fermante;

	i = 0;
	while (lexer->tokens[i] && lexer->tokens[i]->type == TOKEN_WORD)
	{
		chr_ouvrante = ft_strchr(lexer->tokens[i]->str, '"');
		while (chr_ouvrante != NULL)
		{
			printf("quote ouvrante trouvee\n");
			chr_fermante = ft_strchr(chr_ouvrante + 1, '"');
			if (chr_fermante != NULL)
			{
				printf("quote closed dans le meme token\n");
				chr_ouvrante = ft_strchr(chr_fermante + 1, '"');
			}
			else
			{
				printf("on cherche dans les autres tokens\n");
				i++;
				chr_fermante = find_double_quote(lexer, chr_ouvrante, &i);
				if (chr_fermante == NULL)
					chr_ouvrante = NULL;
				else
					chr_ouvrante = ft_strchr(chr_fermante + 1, '"');
			}
		}
		i++;
	}
	if (chr_ouvrante != NULL)
		quote_not_closed(lexer->tokens[i - 1]);
	return ;
}
