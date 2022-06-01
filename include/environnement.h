/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:41:20 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/01 18:48:22 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONNEMENT_H
# define ENVIRONNEMENT_H

typedef struct s_env
{
	char			*line;
	struct s_env	*next;
}	t_env;


/* Function for environnement */
t_env	*init_env(char **env);
char	*search_env(t_env env, char *to_search);
t_env	*default_env(void);


#endif
