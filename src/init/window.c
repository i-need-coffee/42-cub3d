/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:10:57 by username          #+#    #+#             */
/*   Updated: 2026/10/23 17:41:17 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_clean_exit(game, 0);
	return (0);
}

static int	ft_close_game(t_game *game)
{
	ft_clean_exit(game, 0);
	return (0);
}

int	ft_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_exit(game, "mlx", MLX_INIT);
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (game->mlx_win == NULL)
		error_exit(game, "mlx", MLX_WIN);
	init_image(game, &game->image);
	draw_background(game);
	draw_mini_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.img, 0, 0);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, handle_key, game);
	mlx_hook(game->mlx_win, DestroyNotify, ButtonPressMask,
		ft_close_game, game);
	return (0);
}
