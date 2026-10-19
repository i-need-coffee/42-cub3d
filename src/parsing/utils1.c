/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:19:12 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/19 16:31:29 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map_grid(char **grid)
{
	char	**copy_grid;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (grid[count++])
	{
	}
	copy_grid = malloc(sizeof(char *) * (count + 1));
	if (!copy_grid)
		return (NULL);
	while (grid[i])
	{
		copy_grid[i] = ft_strdup(grid[i]);
		i++;
	}
	copy_grid[i] = NULL;
	return (copy_grid);
}

void	flood_fill(char **map, int x, int y, bool *leak)
{
	if (y < 0 || x < 0 || map[y] == NULL
		|| map[y][x] == '\0' || map[y][x] == ' ')
	{
		*leak = true;
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, leak);
	flood_fill(map, x - 1, y, leak);
	flood_fill(map, x, y + 1, leak);
	flood_fill(map, x, y - 1, leak);
}
