/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/30 13:56:56 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing(char *cmd, char **env)
{
	if (cmd == NULL)
		exit(0);
	if (ft_strncmp(cmd, "exit", 10) == 0)
		exit(0);
	if (ft_strncmp(cmd, "pwd", 10) == 0)
		pwd();
	if (ft_strncmp(cmd, "env", 10) == 0)
		envi(env);
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

int	main(int ac, char **av, char **env)
{
	char	*cmd;

	(void) ac;
	(void) av;
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, ctrlc);
		cmd = readline("minishell% ");
		parsing(cmd, env);
	}
	return (0);
}
