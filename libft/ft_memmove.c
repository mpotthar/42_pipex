/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:48:30 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:03:31 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_memmove() function copies len bytes from string src to string dst.
// The two strings may overlap; the copy is always done in a non-destructive
// manner.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = -1;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst < src && (dst != NULL || src != NULL))
	{
		while (++i < len)
			s1[i] = s2[i];
	}
	else if (dst != NULL || src != NULL)
	{
		while (len-- != 0)
			s1[len] = s2[len];
	}
	return (dst);
}
