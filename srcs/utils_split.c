/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:46:18 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/05 16:48:03 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// split cmd by ' '
char	**split_cmd(char *cmd)
{
	// hier verbessern für sng/dbl quotes, split ändern
	char	**cmd_split;

	cmd_split = ft_split(cmd, ' ');
	return (cmd_split);
}