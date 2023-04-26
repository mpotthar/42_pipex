/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:02:15 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 11:53:18 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isprint() function tests for any printing character, including space
// (‘ ’).
int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}
