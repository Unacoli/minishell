/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:24:46 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/20 11:03:34 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Dans le cas ou on a un token DLESS, on envoie le mot qui suit a here_doc
	Here_doc renvoit le fd du fichier dans lequel il a stocke l'info
	ou le pipe dans lequel il a envoye les informations */

int	here_doc(char *delimiter);