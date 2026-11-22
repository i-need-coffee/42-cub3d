/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:48:42 by omiskiny          #+#    #+#             */
/*   Updated: 2026/11/11 12:11:38 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_from_image(t_textinfo *text, int x, int y)
{
	unsigned int	*dst;

	if (x < 0 || y < 0 || x >= text->width || y >= text->height)
		return (0);
	dst = (unsigned int *)(text->addr + (y * text->line_length)
			+ (x * (text->bpp / 8)));
	return (*dst);
}
