/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:08:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/09 12:34:33 by omiskiny         ###   ########.fr       */
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
		return (print_error("NO", DBL_PARAM), false);
	map->no_text = ft_strdup_no_newline(text);
	if (!map->no_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	if (!check_texture_validity(map->no_text))
	{
		free(map->no_text);
		map->no_text = NULL;
		return (false);
	}
	return (true);
}

static bool	set_so_text(t_map *map, char *text)
{
	if (map->so_text != NULL)
		return (print_error("SO", DBL_PARAM), false);
	map->so_text = ft_strdup_no_newline(text);
	if (!map->so_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	if (!check_texture_validity(map->so_text))
	{
		free(map->no_text);
		map->no_text = NULL;
		return (false);
	}
	return (true);
}

static bool	set_we_text(t_map *map, char *text)
{
	if (map->we_text != NULL)
		return (print_error("WE", DBL_PARAM), false);
	map->we_text = ft_strdup_no_newline(text);
	if (!map->we_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	if (!check_texture_validity(map->we_text))
	{
		free(map->no_text);
		map->no_text = NULL;
		return (false);
	}
	return (true);
}

static bool	set_ea_text(t_map *map, char *text)
{
	if (map->ea_text != NULL)
		return (print_error("EA", DBL_PARAM), false);
	map->ea_text = ft_strdup_no_newline(text);
	if (!map->ea_text)
		return (print_error("set_map_texture", ERR_ALLOC), false);
	if (!check_texture_validity(map->ea_text))
	{
		free(map->no_text);
		map->no_text = NULL;
		return (false);
	}
	return (true);
}
