/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:18:37 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/16 17:26:40 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_line_empty(char *line)
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

char	*ft_strdup_no_newline(char *str)
{
	char	*clean_str;
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	clean_str = ft_substr(str, 0, len);
	if (!clean_str)
		return (NULL);
	return (clean_str);
}

bool	check_file(char *file, char *ext)
{
	char	*file_ext;
	int		fd;

	if ((file[0] == '.' && file[1] != '/')
		|| (ft_strrchr(file, '/') && ft_strrchr(file, '/')[1] == '.'))
		return (print_error(file, HID_FILE), false);
	file_ext = ft_strrchr(file, '.');
	if (!file_ext || ft_strcmp(file_ext, ext) != 0)
		return (print_error(file, WRONG_EXT), false);
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (print_error(file, IS_DIR), false);
	}
	return (true);
}

bool	check_texture_validity(char *path)
{
	int	fd;

	if (!path || !check_file(path, ".xpm"))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno)), false);
	close(fd);
	return (true);
}

bool	check_valid_characters(char **grid)
{
	int	i;
	int	j;

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
				printf("Error\n Invalid character '%c' in map.\n", grid[i][j]);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
