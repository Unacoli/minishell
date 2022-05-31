/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:18:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/31 14:25:34 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	great(char *output_file)
{
	int	fd;

	fd = open(output_file, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (fd == -1)
		printf("error");
	return (fd);
}

int	d_great(char *output_file)
{
	int	fd;

	fd = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	if (fd == -1)
		printf("error");
	return (fd);
}