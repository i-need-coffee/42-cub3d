/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:42:23 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 00:51:57 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_number(const char *nptr);
static bool	fill_color(char **color_range, int *color);
static bool	valid_color_range(t_map *map, char **param, char **color_range);

bool	set_map_color(t_map *map, char **param)
{
	char	**color_range;
	int		*color;

	color_range = ft_split(param[1], ',');
	if (!color_range)
		return (print_error("set_map_color", ERR_ALLOC), false);
	if (!valid_color_range(map, param, color_range))
		return (free_char_tab(color_range), false);
	color = ft_calloc(sizeof(int), 3);
	if (!color)
		return (free_char_tab(color_range),
			print_error("set_map_color", ERR_ALLOC), false);
	if (!fill_color(color_range, color))
		return (free(color), free_char_tab(color_range),
			print_error(param[0], WRG_PARAM), false);
	if (ft_strcmp(param[0], "F") == 0)
		map->f_color = color;
	else
		map->c_color = color;
	return (free_char_tab(color_range), true);
}

static bool	valid_color_range(t_map *map, char **param, char **color_range)
{
	if (!color_range[0] || !color_range[1]
		|| !color_range[2] || color_range[3] != NULL)
		return (print_error(param[0], WRG_PARAM), false);
	if ((ft_strcmp(param[0], "F") == 0 && map->f_color != NULL)
		|| (ft_strcmp(param[0], "C") == 0 && map->c_color != NULL))
		return (print_error(param[0], DBL_PARAM), false);
	return (true);
}

static bool	fill_color(char **color_range, int *color)
{
	int	i;

	i = 0;
	while (color_range[i] != NULL)
	{
		color[i] = ft_check_number(color_range[i]);
		if (color[i] == -1)
			return (false);
		i++;
	}
	return (true);
}

static int	ft_check_number(const char *nptr)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	if (!ft_isdigit(nptr[i]))
		return (-1);
	while (ft_isdigit(nptr[i]))
	{
		if (res > 25 || (res == 25 && nptr[i] > '5'))
			return (-1);
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] != '\0')
		return (-1);
	return (res);
}
