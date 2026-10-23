/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_single_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:28:13 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/19 16:30:49 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_player(char c);

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
		print_error("Map grid", INV_PLAYER);
		return (false);
	}
	return (true);
}

static bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}
