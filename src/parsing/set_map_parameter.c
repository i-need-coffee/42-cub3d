/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_parameter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 22:45:52 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 22:45:52 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	apply_map_parameter(t_map *map, char **param, char *line);

bool	set_map_parameter(t_map *map, char *line)
{
	char	**param;

	param = ft_split(line, ' ');
	if (!param)
		return (print_error("set_map_param", ERR_ALLOC), false);
	if (param[0] == NULL || param[1] == NULL || param[2] != NULL)
		return (free_char_tab(param), print_error(line, WRG_PARAM), false);
	if (!apply_map_parameter(map, param, line))
		return (free_char_tab(param), false);
	free_char_tab(param);
	return (true);
}

static bool	apply_map_parameter(t_map *map, char **param, char *line)
{
	if (ft_strcmp(param[0], "NO") == 0 || ft_strcmp(param[0], "SO") == 0
		|| ft_strcmp(param[0], "WE") == 0 || ft_strcmp(param[0], "EA") == 0)
	{
		if (!set_map_texture(map, param))
			return (false);
	}
	else if (ft_strcmp(param[0], "F") == 0 || ft_strcmp(param[0], "C") == 0)
	{
		if (!set_map_color(map, param))
			return (false);
	}
	else
		return (print_error(line, NOT_PARAM), false);
	return (true);
}
