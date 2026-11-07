/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:24:08 by omiskiny          #+#    #+#             */
/*   Updated: 2026/11/07 15:27:02 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall_line(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < game->rays.draw_start)
	{
		my_mlx_put_pixel(&game->image, x, y, 0x87CEEB);
		y++;
	}
	while (y < game->rays.draw_end)
	{
		if (game->rays.side == 0)
			my_mlx_put_pixel(&game->image, x, y, 0xFF0000);
		else
			my_mlx_put_pixel(&game->image, x, y, 0x0000FF);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_put_pixel(&game->image, x, y, 0x228B22);
		y++;
	}
}
