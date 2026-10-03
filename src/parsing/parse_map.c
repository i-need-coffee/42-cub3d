/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:53:52 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/03 17:16:04 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_file(t_game *game, char *file);
static bool	set_map(t_map *map, int fd);
static bool	set_map_param(t_map *map, char *line);

void	parse_map(t_game *game, char *file)
{
	t_map	*map;
	int		fd;

	check_file(game, file);
	game->map = ft_calloc(sizeof(map), 1);
	if (!game->map)
		error_exit(game, "map", ERR_ALLOC);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(game, file, strerror(errno));
	if (!set_map(game->map, fd))
	{
		close(fd);
		exit(1);
	}
	close(fd);
}

static void	check_file(t_game *game, char *file)
{
	char	*ext;
	int		fd;

	if ((file[0] == '.' && file[1] != '/')
		|| (ft_strrchr(file, '/') && ft_strrchr(file, '/')[1] == '.'))
		error_exit(game, file, HID_FILE);
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 5) != 0)
		error_exit(game, file, NOT_CUB);
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		error_exit(game, file, IS_DIR);
	}
}

static bool	set_map(t_map *map, int fd)
{
	char	*line;
	int		nb_params;

	nb_params = 0;
	line = get_next_line(fd);
	if (!line)
		return (print_error("map", IS_EMPTY), false);
	while (line != NULL)
	{
		if (!is_line_empty(line) && nb_params != 5)
		{
			if (!set_map_param(map, line))
				return (free(line), false);
			nb_params++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map = NULL;
	return (true);
}

static bool	set_map_param(t_map *map, char *line)
{
	char	**param;

	param = ft_split(line, ' ');
	if (!param)
		return (print_error("set_map_param", ERR_ALLOC), false);
	if (param[2] != NULL)
		return (free_char_tab(param), print_error(line, WRG_PARAM), false);
	if (ft_strcmp(param[0], "NO") == 0 || ft_strcmp(param[0], "SO") == 0
		|| ft_strcmp(param[0], "WE") == 0 || ft_strcmp(param[0], "EA") == 0)
	{
		if (!set_map_texture(map, param))
			return (free_char_tab(param), false);
	}
	else
		return (free_char_tab(param), print_error(line, NOT_PARAM), false);
	return (true);
}
