/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:20:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 13:31:59 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	temp = lst;
	while (temp)
	{
		new_elem = malloc(sizeof(t_list));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem->content = f(temp->content);
		new_elem->next = NULL;
		if (!new_list)
			new_list = new_elem;
		else
			ft_lstadd_back(&new_list, new_elem);
		temp = temp->next;
	}
	return (new_list);
}
