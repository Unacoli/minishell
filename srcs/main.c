/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/29 16:20:23 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	postparsing(void)
{
	char	*cmd;

	signal(SIGINT, ctrlc);
	cmd = readline("minishell% ");
	parsing(cmd);
}

void	parsing(char *cmd)
{
	if (cmd == NULL)
		exit(0);
	if (ft_strncmp(cmd, "exit", 10) == 0)
		exit(0);
	postparsing();
}

void	ctrlc(int i)
{
	signal(SIGINT, ctrlc);
	i = i + 5;
	rl_on_new_line();
	rl_replace_line("", 1);
	printf("\n");
	rl_redisplay();
}

int	main(int ac, char **av)
{
	char	*cmd;

	(void) ac;
	(void) av;
	signal(SIGINT, ctrlc);
	signal(SIGQUIT, SIG_IGN);
	cmd = readline("minishell% ");
	parsing(cmd);
	return (0);
}
