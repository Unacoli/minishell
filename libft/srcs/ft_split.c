/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:22:20 by nargouse          #+#    #+#             */
/*   Updated: 2021/11/11 18:22:24 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_allocation_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_str;

	if (!s[0])
		return (0);
	i = 0;
	nb_str = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_str++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_str++;
	return (nb_str);
}

static void	get_nextstr(char **next, unsigned int *nextlen, char c)
{
	unsigned int	i;

	*next += *nextlen;
	*nextlen = 0;
	i = 0;
	while (**next && **next == c)
		(*next)++;
	while ((*next)[i])
	{
		if ((*next)[i] == c)
			return ;
		(*nextlen)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_str = ft_get_nb_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_str)
	{
		get_nextstr(&next_str, &next_str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!tab[i])
			return (ft_allocation_error(tab));
		ft_strlcpy(tab[i++], next_str, next_str_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
