/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:50:09 by omiskiny          #+#    #+#             */
/*   Updated: 2026/11/11 11:41:30 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	textures_zero(t_textinfo *tex)
{
	tex->img = NULL;
	tex->addr = NULL;
	tex->bpp = 0;
	tex->line_length = 0;
	tex->endian = 0;
	tex->width = 0;
	tex->height = 0;
}

static void	put_tozero(t_texture *text)
{
	textures_zero(&text->north);
	textures_zero(&text->south);
	textures_zero(&text->west);
	textures_zero(&text->east);
}

static bool	load_single_texture(t_game *game, t_textinfo *text, char *path)
{
	text->img = mlx_xpm_file_to_image(game->mlx, path,
			&text->width, &text->height);
	if (text->img == NULL)
		return (false);
	text->addr = mlx_get_data_addr(text->img, &text->bpp,
			&text->line_length, &text->endian);
	if (text->addr == NULL)
	{
		mlx_destroy_image(game->mlx, text->img);
		return (false);
	}
	return (true);
}

static void	destroy_all_texture(t_game *game, t_texture *text)
{
	if (text->north.img != NULL)
		mlx_destroy_image(game->mlx, text->north.img);
	if (text->south.img != NULL)
		mlx_destroy_image(game->mlx, text->south.img);
	if (text->west.img != NULL)
		mlx_destroy_image(game->mlx, text->west.img);
	if (text->east.img != NULL)
		mlx_destroy_image(game->mlx, text->east.img);
	put_tozero(text);
}

bool	load_all_texture(t_game *game, t_texture *text)
{
	put_tozero(text);
	if (load_single_texture(game, &text->north, game->map->no_text) == false)
	{
		destroy_all_texture(game, text);
		return (false);
	}
	if (load_single_texture(game, &text->south, game->map->so_text) == false)
	{
		destroy_all_texture(game, text);
		return (false);
	}
	if (load_single_texture(game, &text->west, game->map->we_text) == false)
	{
		destroy_all_texture(game, text);
		return (false);
	}
	if (load_single_texture(game, &text->east, game->map->ea_text) == false)
	{
		destroy_all_texture(game, text);
		return (false);
	}
	return (true);
}
