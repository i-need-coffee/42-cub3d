/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:48:05 by omiskiny          #+#    #+#             */
/*   Updated: 2026/11/10 14:38:31 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_destroy(t_game *game, t_img *image)
{
	if (image->img)
	{
		mlx_destroy_image(game->mlx, image->img);
		image->img = NULL;
	}
	image->addr = NULL;
}

int	init_image(t_game *game, t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!image->img)
		return (0);
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
	if (!image->addr)
	{
		image_destroy(game, image);
		return (0);
	}
	return (1);
}
