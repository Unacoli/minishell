/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:43:08 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/12 15:07:57 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 	Fonction echo qui prend en argument une str et l'option -n 
	Elle ecrit sur le terminal str et ajoute \n en fonction de -n
	J'ai mis void parce que je pense pas qu'il puisse avoir de retour d'erreur
	Je pars du principe que la substitution a ete traite en amont */

void	echo(char *str, int option_n)
{
	printf("%s", str);
	if (option_n)
		printf("\n");
}

// char	*echo(char	*cmd, t_env *enviro, int tiretn)
// {
// 	char	*d;
// 	int		i;

// 	i = 0;
// 	d = ft_strdup("");
// 	while (cmd[i])
// 	{
// 		if (cmd[i] != '$')
// 			d = ft_strjoinchar(d, cmd[i]);
// 		else
// 		{
// 			d = ft_strjoin_free2(d, getvale(getname(cmd, i), enviro));
// 			while (cmd[i] != ' ' && cmd[i])
// 				i++;
// 		}
// 		i++;
// 	}
// 	if (tiretn)
// 		return (d);
// 	return (ft_strjoinchar(d, '\n'));
// }
