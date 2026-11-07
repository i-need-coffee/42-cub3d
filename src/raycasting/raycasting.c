/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:48:41 by omiskiny          #+#    #+#             */
/*   Updated: 2026/11/07 15:00:19 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_abs_whichbox(t_game *game)
{
	game->rays.map_cor_x = (int)game->player.x;
	game->rays.map_cor_y = (int)game->player.y;
	game->rays.delta_dist_x = fabs(1.0 / game->rays.ray_dir_x);
	game->rays.delta_dist_y = fabs(1.0 / game->rays.ray_dir_y);
}

static void	set_dda(t_game *game)
{
	set_abs_whichbox(game);
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = (game->player.x - game->rays.map_cor_x)
			* game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_cor_x + 1.0 - game->player.x)
			* game->rays.delta_dist_x;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = (game->player.y - game->rays.map_cor_y)
			* game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_cor_y + 1.0 - game->player.y)
			* game->rays.delta_dist_y;
	}
}

static void	perform_dda(t_game *game)
{
	game->rays.hit_ray = 0;
	while (game->rays.hit_ray == 0)
	{
		if (game->rays.side_dist_x < game->rays.side_dist_y)
		{
			game->rays.side_dist_x += game->rays.delta_dist_x;
			game->rays.map_cor_x += game->rays.step_x;
			game->rays.side = 0;
		}
		else
		{
			game->rays.side_dist_y += game->rays.delta_dist_y;
			game->rays.map_cor_y += game->rays.step_y;
			game->rays.side = 1;
		}
		if (game->map->grid[game->rays.map_cor_y][game->rays.map_cor_x] == '1')
			game->rays.hit_ray = 1;
	}
}

static void	cal_line_height(t_game *game)
{
	if (game->rays.side == 0)
		game->rays.perpwalldist = (game->rays.side_dist_x
				- game->rays.delta_dist_x);
	else
		game->rays.perpwalldist = (game->rays.side_dist_y
				- game->rays.delta_dist_y);
	game->rays.line_height = (int)(WIN_HEIGHT / game->rays.perpwalldist);
	game->rays.draw_start = -game->rays.line_height / 2 + WIN_HEIGHT / 2;
	if (game->rays.draw_start < 0)
		game->rays.draw_start = 0;
	game->rays.draw_end = game->rays.line_height / 2 + WIN_HEIGHT / 2;
	if (game->rays.draw_end >= WIN_HEIGHT)
		game->rays.draw_end = WIN_HEIGHT - 1;
	if (game->rays.side == 0)
		game->rays.wall_x = game->player.y + game->rays.perpwalldist
			* game->rays.ray_dir_y;
	else
		game->rays.wall_x = game->player.x + game->rays.perpwalldist
			* game->rays.ray_dir_x;
	game->rays.wall_x -= floor(game->rays.wall_x);
}

void	cast_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->rays.camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
		game->rays.ray_dir_x = game->player.dir_x
			+ game->player.plane_x * game->rays.camera_x;
		game->rays.ray_dir_y = game->player.dir_y
			+ game->player.plane_y * game->rays.camera_x;
		set_dda(game);
		perform_dda(game);
		cal_line_height(game);
		draw_wall_line(game, x);
		x++;
	}
}
