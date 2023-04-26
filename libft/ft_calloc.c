/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:36:19 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 11:51:22 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_calloc() function contiguously allocates enough space for count
// objects that are size bytes of memory each and returns a pointer to the
// allocated memory.  The allocated memory is filled with bytes of value
// zero.
void	*ft_calloc(size_t count, size_t size)
{
	size_t	totalsize;
	size_t	i;
	void	*pointer;

	totalsize = count * size;
	pointer = malloc(totalsize);
	i = -1;
	if (pointer == NULL)
		return (NULL);
	while (++i < totalsize)
		((char *)pointer)[i] = 0;
	return (pointer);
}
