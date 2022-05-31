/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:12:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/31 14:25:49 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	less(char *input_file)
{
	int	fd;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		printf("error");
	return (fd);
}