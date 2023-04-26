/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:34:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 11:59:59 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_memchr() function locates the first occurrence of c (converted to an
// unsigned char) in string s.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)s;
	c1 = (unsigned char) c;
	while (i < n)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
		i++;
	}
	return (0);
}
