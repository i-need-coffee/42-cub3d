/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:20:51 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/10 17:40:14 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player(t_game *game)
{
	t_player	*player;
	char		**map;
	int			x;
	int			y;

	player = &game->player;
	map = game->map->grid;
	if (game->w_key)
	{
		x = player->x + player->dir_x * MOVE_SPEED;
		if (map[(int)player->y][x] != '1')
			player->x += player->dir_x * MOVE_SPEED;
		y = player->y + player->dir_y * MOVE_SPEED;
		if (map[y][(int)player->x] != '1')
			player->y += player->dir_y * MOVE_SPEED;
	}
	if (game->s_key)
	{
		x = player->x - player->dir_x * MOVE_SPEED;
		if (map[(int)player->y][x] != '1')
			player->x -= player->dir_x * MOVE_SPEED;
		y = player->y - player->dir_y * MOVE_SPEED;
		if (map[y][(int)player->x] != '1')
			player->y -= player->dir_y * MOVE_SPEED;
	}
}
