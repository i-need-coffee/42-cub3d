/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:24:08 by omiskiny          #+#    #+#             */
/*   Updated: 2026/11/11 13:18:50 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < game->rays.draw_start)
	{
		my_mlx_put_pixel(&game->image, x, y, game->map->c_color);
		y++;
	}
}

static void	draw_floor(t_game *game, int x)
{
	int	y;

	y = game->rays.draw_end;
	while (y < WIN_HEIGHT)
	{
		my_mlx_put_pixel(&game->image, x, y, game->map->f_color);
		y++;
	}
}

static int	calculate_tex_x(t_game *game)
{
	int	tex_x;

	tex_x = (int)(game->rays.wall_x * (double)game->texture.north.width);
	if (game->rays.side == 0 && game->rays.ray_dir_x > 0)
		tex_x = game->texture.north.width - tex_x - 1;
	if (game->rays.side == 1 && game->rays.ray_dir_y < 0)
		tex_x = game->texture.north.width - tex_x - 1;
	return (tex_x);
}

static int	get_wall_color(t_game *game, int text_x, int text_y)
{
	if (game->rays.side == 1 && game->rays.ray_dir_y < 0)
		return (get_pixel_from_image(&game->texture.north, text_x, text_y));
	else if (game->rays.side == 1 && game->rays.ray_dir_y > 0)
		return (get_pixel_from_image(&game->texture.south, text_x, text_y));
	else if (game->rays.side == 0 && game->rays.ray_dir_x > 0)
		return (get_pixel_from_image(&game->texture.east, text_x, text_y));
	else
		return (get_pixel_from_image(&game->texture.west, text_x, text_y));
}

void	draw_wall_line(t_game *game, int x)
{
	int		y;
	int		tex_y;
	int		tex_x;
	double	step;
	double	tex_pos;

	tex_x = calculate_tex_x(game);
	draw_ceiling(game, x);
	step = 1.0 * game->texture.north.height / game->rays.line_height;
	tex_pos = (game->rays.draw_start - WIN_HEIGHT / 2
			+ game->rays.line_height / 2) * step;
	y = game->rays.draw_start;
	while (y < game->rays.draw_end)
	{
		tex_y = (int)tex_pos % (game->texture.north.height);
		tex_pos += step;
		my_mlx_put_pixel(&game->image, x, y,
			get_wall_color(game, tex_x, tex_y));
		y++;
	}
	draw_floor(game, x);
}
