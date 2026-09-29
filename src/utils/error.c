/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:14:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/09/29 17:31:58 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *err_msg)
{
	write(2, "\033[31mError\033[0m\n", 15);
	write(2, err_msg, ft_strlen(err_msg));
	write(1, "\n", 1);
}

void	error_exit(char *err_msg)
{
	print_error(err_msg);
	exit(EXIT_FAILURE);
}
