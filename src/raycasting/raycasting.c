/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:48:41 by omiskiny          #+#    #+#             */
/*   Updated: 2026/10/23 17:32:50 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->rays.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		game->rays.ray_dir_x = game->player.dir_x
			+ game->player.plane_x * game->rays.camera_x;
		game->rays.ray_dir_y = game->player.dir_y
			+ game->player.plane_y * game->rays.camera_x;
		x++;
	}
}
