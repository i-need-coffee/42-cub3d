/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:37:20 by username          #+#    #+#             */
/*   Updated: 2026/10/04 18:39:55 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map *map);

void	ft_clean(t_game *game)
{
	if (game != NULL)
	{
		if (game->mlx_win != NULL)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx != NULL)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->map != NULL)
			free_map(game->map);
		free(game);
	}
}

void	ft_clean_exit(t_game *game, int code)
{
	ft_clean(game);
	exit(code);
}

static void	free_map(t_map *map)
{
	if (map->grid != NULL)
		free_char_tab(map->grid);
	if (map->no_text != NULL)
		free(map->no_text);
	if (map->so_text != NULL)
		free(map->so_text);
	if (map->we_text != NULL)
		free(map->we_text);
	if (map->ea_text != NULL)
		free(map->ea_text);
	free(map);
}
