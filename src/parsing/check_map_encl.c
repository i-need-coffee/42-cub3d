/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_encl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:18:33 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/10 14:18:27 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	run_flood_fill(t_map *map, int x, int y)
{
	char	**map_copy;
	bool	leak;

	leak = false;
	map_copy = copy_map_grid(map->grid);
	if (!map_copy)
		return (false);
	flood_fill(map_copy, x, y, &leak);
	free_char_tab(map_copy);
	if (leak == true)
		return (false);
	return (true);
}

bool	check_map_enclosure(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
				return (run_flood_fill(map, x, y));
			x++;
		}
		y++;
	}
	return (false);
}
