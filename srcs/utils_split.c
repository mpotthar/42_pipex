/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:46:18 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/08 10:41:46 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// // split cmd by ' '
// char	**split_cmd(char *cmd)
// {
// 	char	**cmd_split;
// 	// hier verbessern für sng/dbl quotes, split ändern

// 	cmd_split = ft_split(cmd, ' ');
// 	return (cmd_split);
// }

#include "pipex.h"

// searches for a specific character in a string and returns its position
static void	ft_search_for_char(char *s, size_t *i, char c)
{
	if (c == 34 || c == 39)
		(*i)++;
	while (s[*i] != c && s[*i])
		(*i)++;
}

// counts the number of sub-commands in a given string by searching for 
// spaces and accounting for quoted sections.
static int	cnt_sub_cmds(char *s)
{
	size_t	i;
	int		cnt;

	i = -1;
	cnt = 1;
	while (s[++i])
	{
		if (s[i] == ' ')
		{
			ft_search_for_char(s, &i, ' ');
			cnt++;
		}
		if (s[i] == 34 || s[i] == 39)
			ft_search_for_char(s, &i, s[i]);
	}
	return (cnt);
}

// locates a substring in a given string by finding the start and length of
// the substring, accounting for leading spaces and quoted sections.
static void	ft_locate_substr(char *s, size_t *start, size_t *len)
{
	while (s[(*start)] == ' ' && s[(*start)])
		(*start)++;
	(*len) = (*start);
	if (s[(*len)] == 34 || s[(*len)] == 39)
	{
		ft_search_for_char(s, len, s[(*len)]);
		(*start)++;
	}
	else
		ft_search_for_char(s, len, ' ');
}

static void	check_quotes_syntax(char *cmd)
{
	int		dbl_qte;
	int		sng_qte;
	int		i;

	dbl_qte = 0;
	sng_qte = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == 34)
			dbl_qte++;
		else if (cmd[i] == 39)
			sng_qte++;
	}
	if (dbl_qte % 2 != 0 || sng_qte % 2 != 0)
		msg_error("Invalid syntax");
}

char	**split_cmd(char *cmd)
{
	char	**substr;
	int		sub_cmds;
	size_t	start;
	size_t	len;

	check_quotes_syntax(cmd);
	if (cmd == NULL)
		return (NULL);
	substr = (char **) malloc (sizeof(char *) * (cnt_sub_cmds(cmd) + 1));
	if (substr == NULL)
		return (NULL);
	sub_cmds = 0;
	start = 0;
	while (sub_cmds < cnt_sub_cmds(cmd))
	{
		ft_locate_substr(cmd, &start, &len);
		substr[sub_cmds] = ft_substr(cmd, start, len - start);
		if (!substr[sub_cmds])
			return (free_dbl_ptr(substr));
		sub_cmds++;
		start = len;
	}
	substr[sub_cmds] = NULL;
	return (substr);
}
