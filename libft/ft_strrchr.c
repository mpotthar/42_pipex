/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:14:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:09:28 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function is identical to strchr(), except it locates the
// last occurrence of c.
char	*ft_strrchr(const char *s, int c)
{
	char	*lfound;

	lfound = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			lfound = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (lfound);
}
