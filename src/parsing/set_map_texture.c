/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:08:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/03 17:32:40 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	set_no_text(t_map *map, char *text);
static bool	set_so_text(t_map *map, char *text);
static bool	set_we_text(t_map *map, char *text);
static bool	set_ea_text(t_map *map, char *text);

bool	set_map_texture(t_map *map, char **param)
{
	if (ft_strcmp(param[0], "NO") == 0)
	{
		if (!set_no_text(map, param[1]))
			return (false);
	}
	else if (ft_strcmp(param[0], "SO") == 0)
	{
		if (!set_so_text(map, param[1]))
			return (false);
	}
	else if (ft_strcmp(param[0], "WE") == 0)
	{
		if (!set_we_text(map, param[1]))
			return (false);
	}
	else if (ft_strcmp(param[0], "EA") == 0)
	{
		if (!set_ea_text(map, param[1]))
			return (false);
	}
	return (true);
}

static bool	set_no_text(t_map *map, char *text)
{
	if (map->no_text != NULL)
		return (print_error("Map parameter (NO texture)", DBL_PARAM), false);
	map->no_text = ft_strdup(text);
	if (!map->no_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	return (true);
}

static bool	set_so_text(t_map *map, char *text)
{
	if (map->so_text != NULL)
		return (print_error("Map parameter (SO texture)", DBL_PARAM), false);
	map->so_text = ft_strdup(text);
	if (!map->so_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	return (true);
}

static bool	set_we_text(t_map *map, char *text)
{
	if (map->we_text != NULL)
		return (print_error("Map parameter (WE texture)", DBL_PARAM), false);
	map->we_text = ft_strdup(text);
	if (!map->we_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	return (true);
}

static bool	set_ea_text(t_map *map, char *text)
{
	if (map->ea_text != NULL)
		return (print_error("Map parameter (EA texture)", DBL_PARAM), false);
	map->ea_text = ft_strdup(text);
	if (!map->ea_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	return (true);
}
