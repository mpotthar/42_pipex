/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:43:49 by mpotthar          #+#    #+#             */
/*   Updated: 2023/03/28 14:36:38 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	if (len == 0)
		return (NULL);
	if (start >= length)
		len = 0;
	if (start < length)
		length = length - start;
	if (len > length)
		len = length;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = -1;
	while (++i < len && s[start] != '\0')
		sub[i] = s[start++];
	sub[i] = '\0';
	return (sub);
}
