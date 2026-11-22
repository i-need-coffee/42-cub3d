/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:00:55 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/22 02:42:11 by sjolliet         ###   ########.fr       */
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
# include <math.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define WIN_TITLE	"cub3d"
# define MOVE_SPEED	0.05
# define ROT_SPEED	0.04

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

typedef struct s_textinfo
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_textinfo;

typedef struct s_texture
{
	t_textinfo	north;
	t_textinfo	south;
	t_textinfo	west;
	t_textinfo	east;
}	t_texture;

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
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpwalldist;
	double	wall_x;
	int		map_cor_x;
	int		map_cor_y;
	int		step_x;
	int		step_y;
	int		hit_ray;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_rays;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_img		image;
	t_player	player;
	t_rays		rays;
	bool		w_key;
	bool		a_key;
	bool		s_key;
	bool		d_key;
	bool		left_key;
	bool		right_key;
	t_texture	texture;
	t_textinfo	text_info;
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
unsigned int	rgb(int red, int green, int blue);
bool			check_file(char *file, char *ext);
int				init_image(t_game *game, t_img *image);
void			draw_mini_map(t_game *game);
void			init_player(t_player *player, t_map *map);
void			my_mlx_put_pixel(t_img *image, int x, int y, int color);
int				key_release(int keycode, t_game *game);
void			cast_rays(t_game *game);
unsigned int	get_pixel_from_image(t_textinfo *text, int x, int y);
bool			load_all_texture(t_game *game, t_texture *text);
void			draw_wall_line(t_game *game, int x);
int				key_press(int keycode, t_game *game);
int				ft_close_game(t_game *game);
int				game_loop(t_game *game);
void			image_destroy(t_game *game, t_img *image);
void			move_up(t_player *player, char **map);
void			move_down(t_player *player, char **map);
void			move_left(t_player *player, char **map);
void			move_right(t_player *player, char **map);
void			rotate(t_player *player, double rot_speed);
void			destroy_all_texture(t_game *game, t_texture *text);

#endif
