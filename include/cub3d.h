/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:00:55 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/03 15:17:32 by omiskiny         ###   ########.fr       */
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
void	ft_clean_exit(t_game *game, int code);
void	print_error(char *err_msg);
void	error_exit(t_game *game, char *err_msg);
int		ft_mlx_window(t_game *game);

#endif
