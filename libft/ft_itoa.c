/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:12:44 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:28:21 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns the length of int n
static int	ft_n_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int	i;

	i = 1;
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

static void	ft_fill(char *result, int n, int len, int len2)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
		i++;
		len--;
	}
	while (i < len2)
	{
		result[i] = ((n / ft_div(len)) % 10) + 48;
		len--;
		i++;
	}
	result[i] = '\0';
}

// Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.
char	*ft_itoa(int n)
{
	int		len;
	int		len2;
	char	*result;

	len = ft_n_len(n);
	len2 = len;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_fill(result, n, len, len2);
	return (result);
}
