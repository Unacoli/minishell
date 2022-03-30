/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:46 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/30 15:09:50 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoinchar(char const *s1, char const s2)
{
	int		i;
	int		len1;
	char	*dest;

	len1 = ft_strlen(s1);
	dest = malloc(sizeof(char) * (len1 + 2));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	dest[len1] = s2;
	len1++;
	dest[len1] = '\0';
	free((char *)s1);
	return (dest);
}
