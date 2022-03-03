/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:26:23 by nargouse          #+#    #+#             */
/*   Updated: 2021/02/01 15:11:47 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*lst2;

	lst2 = *lst;
	while (lst2)
	{
		temp = lst2->next;
		if (del)
			del(lst2->content);
		free(lst2);
		lst2 = temp;
	}
	*lst = NULL;
}
