/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:41:20 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 03:48:54 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONNEMENT_H
# define ENVIRONNEMENT_H

# include "execution.h"

typedef struct s_env
{
	char			*line;
	struct s_env	*next;
}	t_env;

/* Function for environnement */

t_env	*init_env(char **env);
t_env	*choose_env(char **env);
char	*search_env(t_env env, char *to_search);
t_env	*default_env(void);

/*Function for substitution*/

t_token	handle_substitution(char *input, t_env *env, t_token *rlist);
char	*search_substi(t_env *env, char *str);
char	*substitution(char *str, int position, t_env *env);

int		init_pipex(t_pipe *s_pipe, t_cmd *cmd, t_env *env);
char	**transform_env(t_env *env);

#endif
