/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:42:53 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 22:51:49 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	grid_size(char **grid);
static void	copy_grid(char **dst, char **src);

bool	set_map_grid(t_map *map, char *line)
{
	char	**new_grid;
	char	*row;
	int		count;

	count = grid_size(map->grid);
	new_grid = ft_calloc(count + 2, sizeof(char *));
	if (!new_grid)
		return (print_error("set_map_grid", ERR_ALLOC), false);
	row = ft_strdup_no_newline(line);
	if (!row)
	{
		free(new_grid);
		return (print_error("set_map_grid", ERR_ALLOC), false);
	}
	copy_grid(new_grid, map->grid);
	new_grid[count] = row;
	free(map->grid);
	map->grid = new_grid;
	return (true);
}

static int	grid_size(char **grid)
{
	int	count;

	count = 0;
	while (grid && grid[count])
		count++;
	return (count);
}

static void	copy_grid(char **dst, char **src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
}
