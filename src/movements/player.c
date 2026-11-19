/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:20:51 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/19 17:53:43 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_player *player, char **map, char key);
static void	rotate_player(t_player *player, double rot_speed);

void	update_player(t_game *game)
{
	t_player	*player;
	char		**map;

	player = &game->player;
	map = game->map->grid;
	if (game->w_key)
		move_player(player, map, 'W');
	if (game->s_key)
		move_player(player, map, 'S');
	if (game->a_key)
		move_player(player, map, 'A');
	if (game->d_key)
		move_player(player, map, 'D');
	if (game->left_key)
		rotate_player(player, -ROT_SPEED);
	if (game->right_key)
		rotate_player(player, ROT_SPEED);
}

static void	move_player(t_player *player, char **map, char key)
{
	int		x;
	int		y;

	if (key == 'W')
	{
		x = player->x + player->dir_x * MOVE_SPEED;
		if (map[(int)player->y][x] != '1')
			player->x += player->dir_x * MOVE_SPEED;
		y = player->y + player->dir_y * MOVE_SPEED;
		if (map[y][(int)player->x] != '1')
			player->y += player->dir_y * MOVE_SPEED;
	}
	else if (key == 'S')
	{
		x = player->x - player->dir_x * MOVE_SPEED;
		if (map[(int)player->y][x] != '1')
			player->x -= player->dir_x * MOVE_SPEED;
		y = player->y - player->dir_y * MOVE_SPEED;
		if (map[y][(int)player->x] != '1')
			player->y -= player->dir_y * MOVE_SPEED;
	}
	else if (key == 'A')
	{
		x = player->x + player->dir_y * MOVE_SPEED;
		if (map[(int)player->y][x] != '1')
			player->x += player->dir_y * MOVE_SPEED;
		y = player->y - player->dir_x * MOVE_SPEED;
		if (map[y][(int)player->x] != '1')
			player->y -= player->dir_x * MOVE_SPEED;
	}
	else if (key == 'D')
	{
		x = player->x - player->dir_y * MOVE_SPEED;
		if (map[(int)player->y][x] != '1')
			player->x -= player->dir_y * MOVE_SPEED;
		y = player->y + player->dir_x * MOVE_SPEED;
		if (map[y][(int)player->x] != '1')
			player->y += player->dir_x * MOVE_SPEED;
	}
}

static void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
		- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
		+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}
