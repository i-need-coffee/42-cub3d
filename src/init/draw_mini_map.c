/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:41:52 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/23 09:56:03 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_pixel(t_img *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = image->addr + (y * image->line_length)
		+ (x * (image->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static void	draw_square(t_img *img, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < 10)
	{
		dx = 0;
		while (dx < 10)
		{
			mlx_put_pixel(img, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_mini_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (game->map->grid[y][x] == '1')
				draw_square(&game->image, x * 10, y * 10, rgb(255, 255, 255));
			else if (game->map->grid[y][x] == '0')
				draw_square(&game->image, x * 10, y * 10, rgb(0, 0, 0));
			x++;
		}
		y++;
	}
	draw_square(&game->image, (int)(game->player.x * 10) - 5,
		(int)(game->player.y * 10) - 5, rgb(255, 0, 0));
}
