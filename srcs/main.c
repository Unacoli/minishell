/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/30 15:27:40 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing(char *cmd, char **env)
{
	char	*print;

	if (cmd == NULL)
		exit(0);
	if (ft_strncmp(cmd, "exit", 4) == 0)
	{
		free(cmd);
		exit(0);
	}
	if (ft_strncmp(cmd, "pwd", 3) == 0)
	{
		print = pwd();
		printf("%s", print);
		free(print);
	}
	if (ft_strncmp(cmd, "env", 3) == 0)
	{
		print = envi(env);
		printf("%s", print);
		free(print);
	}
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
		free(cmd);
	}
	return (0);
}
