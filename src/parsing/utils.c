/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:18:37 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 10:18:13 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]) && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

char	*ft_strdup_no_newline(char *str)
{
	char	*clean_str;
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	clean_str = ft_substr(str, 0, len);
	if (!clean_str)
		return (NULL);
	return (clean_str);
}
