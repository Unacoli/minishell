/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:33:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/01 18:36:44 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_node
{
	NODE_PROGRAM = 0,
	NODE_CMD,
	NODE_CMD_SUFFIX,
	NODE_IO_FILE,
	NODE_PIPE_SEQ,
	NODE_SIMPLE_CMD,
	NODE_WORD,
}				t_node;

typedef struct s_ast
{
	t_node			type;
	struct s_ast	*left;
	struct s_ast	*right;
	char			*data;
}				t_ast;

int	parsed_command(t_ast **ast, t_lexer *lexer);
void	create_tree(t_ast **root);
t_ast	create_ast(t_node p_type, char *p_data);
t_ast	*malloc_ast(t_node p_type, char *p_data);

#endif