/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:36:48 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/22 02:16:34 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_clean_exit(game, 0);
	if (keycode == XK_w)
		game->w_key = true;
	if (keycode == XK_s)
		game->s_key = true;
	if (keycode == XK_a)
		game->a_key = true;
	if (keycode == XK_d)
		game->d_key = true;
	if (keycode == XK_Left)
		game->left_key = true;
	if (keycode == XK_Right)
		game->right_key = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->w_key = false;
	if (keycode == XK_s)
		game->s_key = false;
	if (keycode == XK_a)
		game->a_key = false;
	if (keycode == XK_d)
		game->d_key = false;
	if (keycode == XK_Left)
		game->left_key = false;
	if (keycode == XK_Right)
		game->right_key = false;
	return (0);
}

int	ft_close_game(t_game *game)
{
	ft_clean_exit(game, 0);
	return (0);
}

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
