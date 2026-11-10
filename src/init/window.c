/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:10:57 by username          #+#    #+#             */
/*   Updated: 2026/11/10 11:46:25 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_exit(game, "mlx", MLX_INIT);
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (game->mlx_win == NULL)
		error_exit(game, "mlx", MLX_WIN);
	init_image(game, &game->image);
	mlx_hook(game->mlx_win, DestroyNotify, ButtonPressMask,
		ft_close_game, game);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->mlx_win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	return (0);
}
