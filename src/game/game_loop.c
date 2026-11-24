/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 03:24:20 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/22 03:24:31 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	if (game->w_key)
		move_up(&game->player, game->map->grid);
	if (game->s_key)
		move_down(&game->player, game->map->grid);
	if (game->a_key)
		move_left(&game->player, game->map->grid);
	if (game->d_key)
		move_right(&game->player, game->map->grid);
	if (game->left_key)
		rotate(&game->player, -ROT_SPEED);
	if (game->right_key)
		rotate(&game->player, ROT_SPEED);
	cast_rays(game);
	draw_mini_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.img, 0, 0);
	return (0);
}
