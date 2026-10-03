/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:37:20 by username          #+#    #+#             */
/*   Updated: 2026/10/03 15:29:45 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clean_exit(t_game *game, int code)
{
	if (game != NULL)
	{
		if (game->mlx_win != NULL)
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
		}
		if (game->mlx != NULL)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
	exit(code);
}
