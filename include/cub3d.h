/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:00:55 by sjolliet          #+#    #+#             */
/*   Updated: 2026/09/29 17:21:30 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** ================================
**			LIBRARIES
** ================================
*/

# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <mlx.h>
# include <errors.h>

/*
** ================================
**		ENUMS & STRUCTS
** ================================
*/

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
}	t_game;

/*
** ================================
**			FUNCTIONS
** ================================
*/

void	print_error(char *err_msg);
void	error_exit(char *err_msg);

#endif