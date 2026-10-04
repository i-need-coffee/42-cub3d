/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:00:55 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/05 00:12:04 by sjolliet         ###   ########.fr       */
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
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

/*
** ================================
**		ENUMS & STRUCTS
** ================================
*/

typedef struct s_map
{
	char	**grid;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		*f_color;
	int		*c_color;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}	t_game;

/*
** ================================
**			FUNCTIONS
** ================================
*/

void	error_exit(t_game *game, char *err_location, char *err_msg);
void	parse_map(t_game *game, char *file);
void	ft_clean_exit(t_game *game, int code);
void	print_error(char *err_location, char *err_msg);
int		ft_mlx_window(t_game *game);
bool	is_line_empty(char *line);
void	ft_clean(t_game *game);
bool	set_map_texture(t_map *map, char **param);
bool	set_map_color(t_map *map, char **param);

#endif
