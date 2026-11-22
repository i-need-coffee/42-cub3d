/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:23:30 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/20 13:27:03 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x + player->dir_x * MOVE_SPEED;
	if (map[(int)player->y][x] != '1')
		player->x += player->dir_x * MOVE_SPEED;
	y = player->y + player->dir_y * MOVE_SPEED;
	if (map[y][(int)player->x] != '1')
		player->y += player->dir_y * MOVE_SPEED;
}

void	move_down(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x - player->dir_x * MOVE_SPEED;
	if (map[(int)player->y][x] != '1')
		player->x -= player->dir_x * MOVE_SPEED;
	y = player->y - player->dir_y * MOVE_SPEED;
	if (map[y][(int)player->x] != '1')
		player->y -= player->dir_y * MOVE_SPEED;
}

void	move_left(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x + player->dir_y * MOVE_SPEED;
	if (map[(int)player->y][x] != '1')
		player->x += player->dir_y * MOVE_SPEED;
	y = player->y - player->dir_x * MOVE_SPEED;
	if (map[y][(int)player->x] != '1')
		player->y -= player->dir_x * MOVE_SPEED;
}

void	move_right(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x - player->dir_y * MOVE_SPEED;
	if (map[(int)player->y][x] != '1')
		player->x -= player->dir_y * MOVE_SPEED;
	y = player->y + player->dir_x * MOVE_SPEED;
	if (map[y][(int)player->x] != '1')
		player->y += player->dir_x * MOVE_SPEED;
}

void	rotate(t_player *player, double rot_speed)
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
