/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiskiny <omiskiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:09:22 by sjolliet          #+#    #+#             */
/*   Updated: 2026/10/06 10:16:35 by omiskiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARGS	"Program should have one argument (map .cub)"
# define ERR_ALLOC	"Cannot allocate memory"
# define HID_FILE	"Parameter passed is an hidden file"
# define NOT_CUB	"Parameter passed is not a .cub file"
# define IS_DIR		"Is a directory"
# define IS_EMPTY	"Map is empty"
# define MLX_INIT	"mlx_init failed"
# define MLX_WIN	"Window creation failed"
# define WRG_PARAM	"Parameter is not formatted correctly"
# define NOT_PARAM	"Parameter does not exist"
# define DBL_PARAM	"Parameter specified more than once"
# define ERR_GRID	"Empty lines in map grid"

#endif
