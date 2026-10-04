/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:53:52 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 00:55:45 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_file(t_game *game, char *file);
static bool	set_map(t_map *map, int fd);
static bool	set_map_param(t_map *map, char *line);

void	parse_map(t_game *game, char *file)
{
	int		fd;

	check_file(game, file);
	game->map = ft_calloc(sizeof(t_map), 1);
	if (!game->map)
		error_exit(game, "parse_map", ERR_ALLOC);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(game, file, strerror(errno));
	if (!set_map(game->map, fd))
	{
		close(fd);
		(void)get_next_line(-1);
		ft_clean(game);
		exit(EXIT_FAILURE);
	}
	close(fd);
	ft_clean_exit(game, 0);
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
		return (print_error("Map", IS_EMPTY), false);
	while (line != NULL)
	{
		if (!is_line_empty(line) && nb_params < 6)
		{
			if (!set_map_param(map, line))
				return (free(line), false);
			nb_params++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (map->no_text)
		printf("no_text: %s\n", map->no_text);
	if (map->so_text)
		printf("so_text: %s\n", map->so_text);
	if (map->we_text)
		printf("we_text: %s\n", map->we_text);
	if (map->ea_text)
		printf("ea_text: %s\n", map->ea_text);
	if (map->f_color)
		printf("[f_color] r:%d, g:%d, b:%d\n", map->f_color[0], map->f_color[1], map->f_color[2]);
	if (map->c_color)
		printf("[c_color] r:%d, g:%d, b:%d\n", map->c_color[0], map->c_color[1], map->c_color[2]);
	return (true);
}

static bool	set_map_param(t_map *map, char *line)
{
	char	**param;

	param = ft_split(line, ' ');
	if (!param)
		return (print_error("set_map_param", ERR_ALLOC), false);
	if (param[0] == NULL || param[1] == NULL || param[2] != NULL)
		return (free_char_tab(param), print_error(line, WRG_PARAM), false);
	if (ft_strcmp(param[0], "NO") == 0 || ft_strcmp(param[0], "SO") == 0
		|| ft_strcmp(param[0], "WE") == 0 || ft_strcmp(param[0], "EA") == 0)
	{
		if (!set_map_texture(map, param))
			return (free_char_tab(param), false);
	}
	else if (ft_strcmp(param[0], "F") == 0 || ft_strcmp(param[0], "C") == 0)
	{
		if (!set_map_color(map, param))
			return (free_char_tab(param), false);
	}
	else
		return (free_char_tab(param), print_error(line, NOT_PARAM), false);
	free_char_tab(param);
	return (true);
}
