/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:25:10 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/12 13:27:38 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen_without_quotes(char *cmd_line)
{
	char	quote;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
		{
			quote = '\"';
			if (cmd_line[i] == '\'')
				quote = '\'';
			while (cmd_line[++i] && cmd_line[i] != quote)
					count++;
			if (cmd_line[i] && cmd_line[i] == quote)
				i++;
		}
		if (cmd_line[i] && cmd_line[i] != '\'' && cmd_line[i] != '\"')
		{
			i++;
			count++;
		}
	}
	return (count);
}

static char	*ft_copy_element_without_quotes(char *cmd_line, char *new_line)
{
	char	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
		{
			quote = '\"';
			if (cmd_line[i] == '\'')
				quote = '\'';
			while (cmd_line[++i] && cmd_line[i] != quote)
					new_line[j++] = cmd_line[i];
			if (cmd_line[i] && cmd_line[i] == quote)
				i++;
		}
		if (cmd_line[i] && cmd_line[i] != '\'' && cmd_line[i] != '\"')
			new_line[j++] = cmd_line[i++];
	}
	new_line[j] = '\0';
	return (new_line);
}

char	**ft_remove_quotes_from_elements(char **splitted_cmd_line)
{
	int		counter;
	int		j;
	char	*new_line;

	j = 0;
	while (splitted_cmd_line[j])
	{
		counter = ft_strlen_without_quotes(splitted_cmd_line[j]);
		new_line = malloc((counter + 1) * sizeof(char));
		if (!new_line)
		{
			perror("malloc - remove quotes from elements");
			return (free_dbl_ptr(splitted_cmd_line));
		}
		ft_copy_element_without_quotes(splitted_cmd_line[j], new_line);
		free(splitted_cmd_line[j]);
		splitted_cmd_line[j] = new_line;
		j++;
	}
	return (splitted_cmd_line);
}
