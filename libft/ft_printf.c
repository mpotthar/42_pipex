/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:23:22 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/06 10:20:58 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long int num, char *base, int len, int *cnt)
{
	if (num < 0)
	{
		*cnt += write(1, "-", 1);
		num *= -1;
	}
	if (num >= len)
		ft_putnbr(num / len, base, len, cnt);
	ft_putchar_fd(base[num % len], 1);
	*cnt += 1;
}

static void	ft_putnbr_uns(long unsigned int num, char *base, int len, int *cnt)
{
	if (num >= (unsigned long int)len)
		ft_putnbr_uns(num / len, base, len, cnt);
	ft_putchar_fd(base[num % len], 1);
	*cnt += 1;
}

static void	ft_print_string(char *s, int *cnt, int pointer)
{
	if (pointer == 0)
	{
		if (s == NULL)
			*cnt += write(1, "(null)", 6);
		else
			*cnt += write(1, s, (int)ft_strlen(s));
	}
	else if (pointer == 1)
	{
		ft_putstr_fd("0x", 1);
		*cnt += 2;
		ft_putnbr_uns((long unsigned int)s, "0123456789abcdef", 16, cnt);
	}
}

static int	ft_cases(va_list arg_list, char c, int *cnt)
{
	if (c == 'c')
	{
		*cnt += 1;
		ft_putchar_fd(va_arg(arg_list, int), 1);
	}
	else if (c == '%')
		*cnt += write(1, "%", 1);
	else if (c == 's')
		ft_print_string(va_arg(arg_list, char *), cnt, 0);
	else if (c == 'p')
		ft_print_string(va_arg(arg_list, void *), cnt, 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg_list, int), "0123456789", 10, cnt);
	else if (c == 'u')
		ft_putnbr(va_arg(arg_list, unsigned int), "0123456789", 10, cnt);
	else if (c == 'x')
		ft_putnbr(va_arg(arg_list, unsigned int), "0123456789abcdef", 16, cnt);
	else if (c == 'X')
		ft_putnbr(va_arg(arg_list, unsigned int), "0123456789ABCDEF", 16, cnt);
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		cnt;
	va_list	arg_list;

	i = -1;
	cnt = 0;
	va_start(arg_list, input);
	while (input[++i])
	{
		if (input[i] == '%')
		{
			if (ft_cases(arg_list, input[++i], &cnt) == -1)
			{
				va_end(arg_list);
				return (-1);
			}	
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			cnt++;
		}
	}
	va_end(arg_list);
	return (cnt);
}
