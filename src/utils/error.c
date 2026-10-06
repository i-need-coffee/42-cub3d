/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:14:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/04 20:30:05 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *err_location, char *err_msg)
{
	size_t	loc_len;

	write(2, "\033[31mError\033[0m\n", 15);
	loc_len = ft_strlen(err_location);
	if (loc_len > 0 && err_location[loc_len - 1] == '\n')
		loc_len--;
	write(2, err_location, loc_len);
	write(2, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
}

void	error_exit(t_game *game, char *err_location, char *err_msg)
{
	print_error(err_location, err_msg);
	ft_clean_exit(game, EXIT_FAILURE);
}
