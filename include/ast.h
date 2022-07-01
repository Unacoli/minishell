/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:33:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/02 00:14:27 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_node
{
	NODE_PROGRAM = 0,
	NODE_CMD,
	NODE_PIPE_SEQ,
	NODE_SIMPLE_CMD,
	NODE_CMD_SUFFIX,
	NODE_IO_FILE,
	NODE_WORD,
}				t_node;

typedef struct s_ast
{
	t_node			type;
	struct s_ast	*left;
	struct s_ast	*right;
	char			*data;
}				t_ast;

int		cmd_suffix(t_ast *ast, t_lexer *lexer);
int		simple_command(t_ast *ast, t_lexer *lexer);
int		io_file(t_ast *ast, t_lexer *lexer);
int		parsed_command(t_ast **ast, t_lexer *lexer);
void	create_root(t_ast **root);
t_ast	create_ast(t_node p_type, char *p_data);
t_ast	*malloc_ast(t_node p_type, char *p_data);
int		parse(t_ast **root, t_lexer *lexer);

#endif
