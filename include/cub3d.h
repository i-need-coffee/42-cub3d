/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:00:55 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/16 16:59:58 by sjolliet         ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WIN_TITLE	"cub3d"

/*
** ================================
**		ENUMS & STRUCTS
** ================================
*/

typedef struct s_map
{
	char			**grid;
	char			*no_text;
	char			*so_text;
	char			*we_text;
	char			*ea_text;
	unsigned int	f_color;
	unsigned int	c_color;
	bool			f_color_set;
	bool			c_color_set;
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

void			error_exit(t_game *game, char *err_location, char *err_msg);
void			parse_map(t_game *game, char *file);
void			ft_clean_exit(t_game *game, int code);
void			print_error(char *err_location, char *err_msg);
void			flood_fill(char **map, int x, int y, bool *leak);
int				ft_mlx_window(t_game *game);
bool			is_line_empty(char *line);
void			ft_clean(t_game *game);
bool			set_map_texture(t_map *map, char **param);
bool			check_texture_validity(char *path);
bool			check_valid_characters(char **grid);
bool			check_single_player(char **grid);
bool			check_map_enclosure(t_map *map);
bool			set_map_color(t_map *map, char **param);
bool			set_map_grid(t_map *map, char *line);
bool			set_map_parameter(t_map *map, char *line);
char			*ft_strdup_no_newline(char *str);
char			**copy_map_grid(char **grid);
int				handle_key(int keycode, t_game *game);
unsigned int	rgb(int red, int green, int blue);
bool			check_file(char *file, char *ext);

#endif
