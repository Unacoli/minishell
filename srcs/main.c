/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/11 17:46:07 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing(char *cmd, t_env *enviro)
{
	char	*print;

	print = NULL;
	if (cmd == NULL)
		exitfree(enviro);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
	{
		free(cmd);
		exitfree(enviro);
	}
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
	{
		print = pwd();
		if (print)
		{
			printf("%s", print);
			free(print);
		}
	}
	else if (ft_strncmp(cmd, "env", 3) == 0)
	{
		print = envi(enviro);
		if (print)
		{
			printf("%s", print);
			free(print);
		}
	}
	else if (ft_strncmp(cmd, "export", 6) == 0)
	{
		cmd = cmd + 7;
		print = export(cmd, enviro);
		if (print)
		{
			printf("%s", print);
			free(print);
		}
	}
	else if (ft_strncmp(cmd, "unset", 5) == 0)
	{
		cmd = cmd + 6;
		unset(cmd, enviro);
	}
	else if (ft_strncmp(cmd, "cd", 2) == 0)
	{
		cmd = cmd + 3;
		print = cd(cmd);
		if (print)
		{
			printf("%s", print);
			free(print);
		}
	}
	else if (ft_strncmp(cmd, "echo", 4) == 0)
	{
		cmd = cmd + 4;
		print = echo(cmd, enviro, 0);
		if (print)
		{
			printf("%s", print);
			free(print);
		}
	}
	else
		lexe(cmd, enviro);
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
	t_env	*enviro;

	(void) ac;
	(void) av;
	enviro = initenv(env);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, ctrlc);
		cmd = readline("minishell% ");
		parsing(cmd, enviro);
		free(cmd);
	}
	return (0);
}
