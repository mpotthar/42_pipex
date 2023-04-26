/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:56:06 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:13:05 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlcat() appends string src to the end of dst.  It will append at most
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
// dstsize is 0 or the original dst string was longer than dstsize. 
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s_src;
	size_t	len_dst;
	size_t	len_src;
	size_t	rem;
	size_t	i;

	s_src = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s_src);
	rem = 0;
	i = 0;
	if (dstsize > len_dst)
		rem = len_src + len_dst;
	else
		rem = len_src + dstsize;
	while (s_src[i] != '\0' && ((len_dst + 1) < dstsize))
	{
		dst[len_dst] = s_src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (rem);
}
