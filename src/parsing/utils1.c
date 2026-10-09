/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:19:12 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/09 11:56:19 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	check_single_player(char **grid)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j])
		{
			if (is_player(grid[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		print_error("Player", "Wrong number of players\n");
		return (false);
	}
	return (true);
}

unsigned int	rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
