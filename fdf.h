/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:41:38 by mpascual          #+#    #+#             */
/*   Updated: 2025/07/24 13:32:55 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "lib/libft/libft.h"
# include "lib/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>

/* Set the corresponding keycode table for the current OS */
# if defined __linux__
#  include "headers/mlx_input_linux.h"
# else
#  include "headers/mlx_input.h"
# endif
# include "headers/colors.h"

/* Set default screen resolution (to be changed at compile time by Makefile) */
# ifndef SCREEN_RES_X
#  define SCREEN_RES_X 1920
# endif
# ifndef SCREEN_RES_Y
#  define SCREEN_RES_Y 1080
# endif

typedef struct s_voxel
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_voxel;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

/* 💀 Nested structs chaos courtesy of the fucking mlx_hook function 💀 */
typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win;
	int			img_width;
	int			img_height;
	t_img_data	img;
}	t_mlx_data;

typedef struct s_map_tools
{
	int		fd;
	int		columns;
	int		rows;
	int		x_offset;
	int		y_offset;
	int		z_max;
	int		xy_scale;
	int		z_scale;
	t_voxel	**map;
}	t_map_tools;

typedef struct s_vars
{
	t_mlx_data	mlx;
	t_map_tools	mtools;
}	t_vars;

/* from utils.c */
void	clean_exit(char error_code, t_mlx_data *mlx, t_map_tools *mtools);
void	diy_pixel_put(t_mlx_data *mlx, int x, int y, int color);
t_pixel	voxtopix(t_voxel source, t_map_tools *mtools);
int		close_win(t_vars *vars);
void	clear_screen(t_mlx_data *mlx);
void	leak_check(void);
// from main.c
void	init_vars(t_mlx_data *mlx, t_map_tools *mtools);
void	set_scale(t_mlx_data *mlx, t_map_tools *mtools);
int		keypress(int keycode, t_vars *vars);
/* from read.c*/
int		read_map(t_map_tools *mtools);
/* from store_map.c */
void	free_map(t_map_tools *mtools);
int		store_map(t_map_tools *mtools, char **aux);
/* from draw.c */
int		draw_line_low(t_mlx_data *mlx, t_pixel a, t_pixel b);
int		draw_line_high(t_mlx_data *mlx, t_pixel a, t_pixel b);
void	draw_map(t_map_tools *mtools, t_mlx_data *mlx);

#endif
