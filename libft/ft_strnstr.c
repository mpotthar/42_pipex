/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:35:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:22:17 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_strnstr() function locates the first occurrence of the null-
// terminated string needle in the string haystack, where not more than len
// characters are searched.  Characters that appear after a ‘\0’ character
// are not searched.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle == NULL)
		return ((char *)haystack);
	while (len >= needle_len && haystack_len >= needle_len)
	{
		len--;
		haystack_len--;
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
