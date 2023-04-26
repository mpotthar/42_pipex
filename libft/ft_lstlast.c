/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:33:02 by mpotthar          #+#    #+#             */
/*   Updated: 2022/12/22 15:47:46 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	len = ft_lstsize(lst) - 1;
	while (++i < len)
		lst = lst->next;
	return (lst);
}
