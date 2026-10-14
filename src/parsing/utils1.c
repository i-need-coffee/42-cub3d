/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:19:12 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/10 12:11:20 by omiskiny         ###   ########.fr       */
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
