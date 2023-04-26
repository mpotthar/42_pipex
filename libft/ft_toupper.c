/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:10:29 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/02 12:27:19 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_toupper() function converts a lower-case letter to the corresponding
// upper-case letter. 
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c + ('A' - 'a');
	return (c);
}
