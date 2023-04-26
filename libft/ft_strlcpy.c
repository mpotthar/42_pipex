/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:38:42 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:13:45 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlcpy() copies up to dstsize - 1 characters from the string src to dst,
// NUL-terminating the result if dstsize is not 0.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	cpy;

	cnt = 0;
	cpy = 0;
	while (src[cnt] != '\0')
	{
			cnt++;
	}
	if (dstsize != 0)
	{
		while (src[cpy] != '\0' && cpy < (dstsize - 1))
		{
			dst[cpy] = src[cpy];
			cpy++;
		}
		dst[cpy] = '\0';
	}
	return (cnt);
}
