/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:37:20 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/05 16:53:01 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strjoin_line(char *s1, char *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		len;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 1;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len1);
	new[len1] = '\n';
	ft_memcpy(new + len1 + 1, s2, len2);
	new[len] = 0;
	return (new);
}

char	*strjoin_line_free(char *s1, char *s2)
{
	char	*new;

	new = strjoin_line(s1, s2);
	free(s1);
	free(s2);
	return (new);
}

int	get_line(char **line)
{
	int	ret;
	char *tmp;

	ret = get_next_line(0, line);
	while (ret && *line)
	{
		ret = get_next_line(0, &tmp);
		if (ret < 0 || !tmp)
		(
			free(*line);
			*line = NULL;
			return (ret);
		}
		*line = strjoin_line_free(*line, tmp);
	}
	(!*line)
		return (-1);
	return (ret);
}

char	**parse_line_into_tab(char **line)
{
	char	*line_tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	get_line(line);
	*line_tab = malloc(sizeof(char) * ft_strlen(line[i]));
	while (*line[i] != '\0')
	{
		if (*line[i] == ' ')
		{
			i++;
			j++;
		}
		line_tab[j] = *line[i];
		i++;
	}
	j++;
	line_tab[j] = '\0';
	free(line);
}

