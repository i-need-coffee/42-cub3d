/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:18:37 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/03 16:30:27 by sjolliet         ###   ########.fr       */
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
