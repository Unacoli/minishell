/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:06:35 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 19:31:00 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_if(char **left, char **tmp)
{
	*tmp = *left;
	if (*left)
		*left = ft_strdup(ft_strchr(*left, '\n') + 1);
	else
		*left = ft_strdup(ft_strchr("", '\n') + 1);
	free(*tmp);
	return (1);
}

static char	*ft_tern1(char *left)
{
	if (left)
		return (ft_strndup(left, ft_strichr(left, '\n')));
	else
		return (ft_strndup("", ft_strichr("", '\n')));
}

static char	*ft_tern2(char *left)
{
	if (left)
		return (ft_strchr(left, '\n'));
	else
		return (ft_strchr("", '\n'));
}

int	get_next_line(int fd, char **line)
{
	static char	*left = NULL;
	char		buf[BUFSIZE + 1];
	int			ret;
	char		*tmp;

	ft_bzero(buf, BUFSIZE + 1);
	if (fd < 0 || line == NULL || BUFSIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	*line = ft_tern1(left);
	if (ft_tern2(left) != NULL)
		return (ft_if(&left, &tmp));
	ret = read(fd, &buf, BUFSIZE);
	while ((ret > 0) && ft_strchr(buf, '\n') == 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin_free(*line, buf);
		ret = read(fd, &buf, BUFSIZE);
	}
	buf[ret] = '\0';
	*line = ft_strnjoin_free(*line, buf, ft_strichr(buf, '\n'));
	if (ret != BUFSIZE && ft_strchr(buf, '\n') == NULL)
		return (ft_free((void **)&left));
	tmp = left;
	left = ft_strdup(ft_strchr(buf, '\n') + 1);
	return (free(tmp), 1);
}
