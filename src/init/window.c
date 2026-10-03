/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:10:57 by username          #+#    #+#             */
/*   Updated: 2026/10/03 15:31:14 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_exit(game, ERR_MLX_INIT);
	game->mlx_win = mlx_new_window(game->mlx, 800, 600, "cub3d - test window");
	if (game->mlx_win == NULL)
		error_exit(game, ERR_MLX_WIN);
	return (0);
}
