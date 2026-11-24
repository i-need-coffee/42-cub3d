/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:09:22 by sjolliet          #+#    #+#             */
/*   Updated: 2026/11/22 03:07:52 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARGS	"Program should have one argument (map .cub)"
# define ERR_ALLOC	"Cannot allocate memory"
# define HID_FILE	"Parameter passed is an hidden file"
# define WRONG_EXT	"Incorrect or missing file extension"
# define IS_DIR		"Is a directory"
# define IS_EMPTY	"Map is empty"
# define MLX_INIT	"mlx_init failed"
# define MLX_WIN	"Window creation failed"
# define WRG_PARAM	"Parameter is not formatted correctly"
# define NOT_PARAM	"Parameter does not exist"
# define DBL_PARAM	"Parameter specified more than once"
# define ERR_GRID	"Empty lines in map grid"
# define WRONG_CHAR	"Invalid character found in map grid"
# define INV_PLAYER	"Number of players is incorrect"
# define WRONG_PATH	"Not entirely enclosed by walls or has spaces within walls"
# define WRONG_XPM	"Failed to load .xpm files"
# define MLX_IMG	"Image creation failed"

#endif
