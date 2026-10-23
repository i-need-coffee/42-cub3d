/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:53:52 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/19 16:26:17 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	read_map_parameters(t_map *map, int fd);
static bool	read_map_grid(t_map *map, int fd);
static bool	process_grid_line(t_map *map, char *line, bool *start_grid,
				bool *finish_grid);
static bool	check_valid_characters(char **grid);

void	parse_map(t_game *game, char *file)
{
	int		fd;

	if (!check_file(file, ".cub"))
		ft_clean_exit(game, EXIT_FAILURE);
	game->map = ft_calloc(sizeof(t_map), 1);
	if (!game->map)
		error_exit(game, "parse_map", ERR_ALLOC);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(game, file, strerror(errno));
	if (!read_map_parameters(game->map, fd)
		|| !read_map_grid(game->map, fd)
		|| !check_valid_characters(game->map->grid)
		|| !check_single_player(game->map->grid)
		|| !check_map_enclosure(game->map))
	{
		close(fd);
		get_next_line(-1);
		ft_clean_exit(game, EXIT_FAILURE);
	}
	close(fd);
}

static bool	read_map_parameters(t_map *map, int fd)
{
	char	*line;
	int		nb_params;

	line = get_next_line(fd);
	if (!line)
		return (print_error("Map", IS_EMPTY), false);
	nb_params = 0;
	while (line != NULL && nb_params < 6)
	{
		if (!is_line_empty(line))
		{
			if (!set_map_parameter(map, line))
				return (free(line), false);
			nb_params++;
		}
		free(line);
		if (nb_params == 6)
			return (true);
		line = get_next_line(fd);
	}
	free(line);
	return (true);
}

static bool	read_map_grid(t_map *map, int fd)
{
	char	*line;
	bool	start_grid;
	bool	finish_grid;

	start_grid = false;
	finish_grid = false;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_grid_line(map, line, &start_grid, &finish_grid))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	if (!start_grid)
		return (print_error("Map", IS_EMPTY), false);
	return (true);
}

static bool	process_grid_line(t_map *map, char *line, bool *start_grid,
		bool *finish_grid)
{
	if (is_line_empty(line))
	{
		if (*start_grid)
			*finish_grid = true;
		return (true);
	}
	if (*finish_grid)
		return (print_error("Map", ERR_GRID), false);
	*start_grid = true;
	return (set_map_grid(map, line));
}

static bool	check_valid_characters(char **grid)
{
	int		i;
	int		j;
	char	str[2];

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] != '0' && grid[i][j] != '1' && grid[i][j] != 'W' &&
					grid[i][j] != 'E' && grid[i][j] != 'S' &&
						grid[i][j] != 'N' && grid[i][j] != ' ')
			{
				str[0] = grid[i][j];
				str[1] = '\0';
				print_error(WRONG_CHAR, str);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
