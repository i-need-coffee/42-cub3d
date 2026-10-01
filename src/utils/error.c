/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:14:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/01 16:31:03 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *err_location, char *err_msg)
{
	write(2, "\033[31mError\033[0m\n", 15);
	write(2, err_location, ft_strlen(err_location));
	write(1, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(1, "\n", 1);
}

void	error_exit(char *err_location, char *err_msg)
{
	print_error(err_location, err_msg);
	exit(EXIT_FAILURE);
}
