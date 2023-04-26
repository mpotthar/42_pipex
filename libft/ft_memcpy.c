/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:01:46 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:02:05 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_memcpy() function copies n bytes from memory area src to memory area
// dst.  If dst and src overlap, behavior is undefined.  Applications in
// which dst and src might overlap should use ft_memmove(3) instead.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = -1;
	while (++i < n && (dst != NULL || src != NULL))
		s1[i] = s2[i];
	return (dst);
}
