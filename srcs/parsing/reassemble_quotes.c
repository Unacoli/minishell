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

// echo 12345 67"890 a bcd efgh ij"

#include "minishell.h"

static void	quote_closed_in_another_token(t_lexer *lexer, int i_ouvrante, int i_fermante)
{
	int	len;
	int	i;
	t_token *new;
	char	*str_new;
	int	k = 0;
	int j = 0;

	i = i_ouvrante - 1;
	len = 0;
	while (i < i_fermante)
		len += lexer->tokens[i++]->len;
	str_new = ft_newstr(len + 1);
	
	i = i_ouvrante - 1;
	j = 0;
	while (i < i_fermante)
	{
		k = 0;
		while (lexer->tokens[i]->str[k] != '\0')
		{
			str_new[j] = lexer->tokens[i]->str[k];
			k++;
			j++;
		}
		i++;
	}
	new = malloc_token(str_new, len, TOKEN_WORD);

	t_token **new_tokens;
	printf("taille newt tokens: %lu\n", lexer->size - (i_fermante - i_ouvrante));
	printf("offset: %d\n", i_fermante - i_ouvrante + 1);
	printf("iuv: %d\n", i_ouvrante);
	new_tokens = (t_token **)ft_calloc(lexer->size - (i_fermante - i_ouvrante), sizeof(t_token *));
	k = 0;

	while (k < i_ouvrante - 1)
	{
		new_tokens[k] = lexer->tokens[k];
		k++;
	}
	new_tokens[k++] = new;
	while (k < (int)lexer->size - (i_fermante - i_ouvrante))
	{
		printf("k: %d\nk:%d\n\n", k, k + (i_fermante - i_ouvrante - 1));
		new_tokens[k] = lexer->tokens[k + (i_fermante - i_ouvrante - 1)];
		k++;
	}

	free_tokens(lexer);
	lexer->tokens = new_tokens;
	lexer->size = k;
	lexer->capacity = k;

	return ;
}

static void	quote_not_closed(t_token *token)
{
	token->type = TOKEN_NOT_VALID;
	ft_putstr_fd("Quote is not closed !\n", STDERR_FILENO);
	g_status = 1;
}

static char	*find_double_quote(t_lexer *lexer, int *i)
{
	char		*chr_fermante;
	const int	i_ouvrante = *i;

	while (lexer->tokens[*i] && (lexer->tokens[*i]->type == TOKEN_WORD || lexer->tokens[*i]->type == TOKEN_BLANK))
	{
		chr_fermante = ft_strchr(lexer->tokens[*i]->str, '"');
		if (chr_fermante != NULL)
		{
			(*i)++;
			quote_closed_in_another_token(lexer, i_ouvrante, *i);
			return (chr_fermante);
		}
		(*i)++;
	}
	quote_not_closed(lexer->tokens[*i - 1]);
	return (NULL);
}

void	reassemble_quotes(t_lexer *lexer)
{
	int		i;
	char	*chr_ouvrante;
	char	*chr_fermante;

	i = 0;
	while (lexer->tokens[i] && (lexer->tokens[i]->type == TOKEN_WORD || lexer->tokens[i]->type == TOKEN_BLANK))
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
				chr_fermante = find_double_quote(lexer, &i);
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
