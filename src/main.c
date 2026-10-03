/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:37:44 by username          #+#    #+#             */
/*   Updated: 2026/10/03 15:27:53 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	(void) argv;
	if (argc != 2)
		error_exit(NULL, ERR_ARGS);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		error_exit(NULL, ERR_ALLOC);
	ft_mlx_window(game);
	mlx_loop(game->mlx);
	return (0);
}
