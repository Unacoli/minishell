/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:50:19 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 10:30:03 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <string.h>
# include "environnement.h"

/*Structs for execution*/

typedef struct s_simplecmd
{
	size_t	ac;
	char	**av;
	char	*input_file;
	char	*output_file;
}				t_simplecmd;

typedef struct s_cmd
{
	size_t		cap;
	size_t		cmd_count;
	t_simplecmd	**simple_cmd;
}				t_cmd;

/* Substitution functions */
char	*search_substi(t_env *env, char *str);
char	*substitution(char *str, int position, t_env *env);
char	*make_3_str(char *str, int position, int j, char *value);
char	*join_3_str(char *before, char *substi, char *after);

#endif