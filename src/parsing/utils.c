/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:18:37 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/09 10:27:40 by omiskiny         ###   ########.fr       */
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

bool	check_texture_validity(char *path)
{
	int	fd;
	int	len;

	if (!path)
		return (false);
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + (len - 4), ".xpm", 4) != 0)
	{
		printf("Error!\n Invalid extension in path: '%s'\n", path);
		return (false);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\n File can't open\n");
		return (false);
	}
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
