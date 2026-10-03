/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:53:52 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/03 16:03:55 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_file(t_game *game, char *file);
static bool	set_map(t_map *map, int fd);
static bool	is_empty(char *line);

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

	line = get_next_line(fd);
	if (!line)
		return (print_error("map", IS_EMPTY), false);
	while (line != NULL)
	{
		if (is_empty(line))
			printf("is empty");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map = NULL;
	return (true);
}

static bool	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]) && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
