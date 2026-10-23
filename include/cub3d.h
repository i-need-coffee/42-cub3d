/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:00:55 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/23 17:46:14 by omiskiny         ###   ########.fr       */
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

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define WIN_TITLE	"cub3d"
# define TILE_SIZE	10

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_rays
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
}	t_rays;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_img		image;
	t_player	player;
	t_rays		rays;
}	t_game;

/*
** ================================
**			FUNCTIONS
** ================================
*/

// Parsing
void			error_exit(t_game *game, char *err_location, char *err_msg);
void			parse_map(t_game *game, char *file);
void			ft_clean_exit(t_game *game, int code);
void			print_error(char *err_location, char *err_msg);
int				ft_mlx_window(t_game *game);
bool			is_line_empty(char *line);
void			ft_clean(t_game *game);
bool			set_map_texture(t_map *map, char **param);
bool			check_texture_validity(char *path);
bool			check_single_player(char **grid);
bool			check_map_enclosure(t_map *map);
bool			set_map_color(t_map *map, char **param);
bool			set_map_grid(t_map *map, char *line);
bool			set_map_parameter(t_map *map, char *line);
char			*ft_strdup_no_newline(char *str);
int				handle_key(int keycode, t_game *game);
unsigned int	rgb(int red, int green, int blue);
bool			check_file(char *file, char *ext);

// MLX
int				init_image(t_game *game, t_img *image);
void			draw_mini_map(t_game *game);
void			init_player(t_player *player, t_map *map);
void			mlx_put_pixel(t_img *image, int x, int y, int color);
void			draw_background(t_game *game);

// Raycasting
void			cast_rays(t_game *game);

#endif
