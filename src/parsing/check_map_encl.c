/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_encl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:18:33 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/23 16:19:33 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	has_spaces_around(char **grid, int x, int y);

bool	check_map_enclosure(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->grid || !map->grid[0])
		return (print_error("Map grid", WRONG_PATH), false);
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (ft_strchr("0NSEW", map->grid[y][x])
					&& has_spaces_around(map->grid, x, y))
				return (print_error("Map grid", WRONG_PATH), false);
			x++;
		}
		y++;
	}
	return (true);
}

static bool	has_spaces_around(char **grid, int x, int y)
{
	if (x == 0 || y == 0 || !grid[y + 1])
		return (true);
	if (x >= (int)ft_strlen(grid[y - 1])
		|| x >= (int)ft_strlen(grid[y + 1]))
		return (true);
	if (grid[y][x - 1] == ' ' || grid[y][x + 1] == ' '
		|| grid[y][x + 1] == '\0')
		return (true);
	if (grid[y - 1][x] == ' ' || grid[y + 1][x] == ' ')
		return (true);
	return (false);
}
