/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:41 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:09:58 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_strdup() function allocates sufficient memory for a copy of the
// string s1, does the copy, and returns a pointer to it.  The pointer may
// subsequently be used as an argument to the function free(3).
char	*ft_strdup(const char *s1)
{
	size_t	totalsize;
	size_t	i;
	char	*pointer;

	totalsize = ft_strlen(s1) + 1;
	pointer = malloc(totalsize);
	i = -1;
	if (pointer == NULL)
		return (NULL);
	while (++i < totalsize)
		((char *)pointer)[i] = s1[i];
	return (pointer);
}
