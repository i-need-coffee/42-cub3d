/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:37:44 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 01:03:23 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_exit(NULL, "cub3d", ERR_ARGS);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		error_exit(NULL, "game creation", ERR_ALLOC);
	parse_map(game, argv[1]);
	ft_mlx_window(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
