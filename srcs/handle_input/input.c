/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/03 11:58:04 by ldubuche         ###   ########.fr       */
=======
/*   Updated: 2022/06/09 04:17:28 by nargouse         ###   ########.fr       */
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
<<<<<<< HEAD
		printf("If this success until here i'm really happy\n");
	exit_free(minishell);
=======
	{
		/*Create function to follow the ast*/
		exit(0);
	}
	destroy_shell(minishell);
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
}
