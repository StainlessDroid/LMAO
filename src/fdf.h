/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:41:38 by mpascual          #+#    #+#             */
/*   Updated: 2023/04/24 18:40:12 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

/* Set the corresponding keycode table for the current OS */
# if defined __linux__
#  include "headers/mlx_input_linux.h"
# else
#  include "headers/mlx_input.h"
# endif
# include "headers/colors.h"

typedef struct  s_img_data
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}               t_img_data;

typedef struct  s_mlx_data
{
    void    *mlx;
    void    *win;
    int     img_width;
    int     img_height;
    t_img_data img;
}               t_mlx_data;

typedef struct  s_voxel
{
    int x;
    int y;
    int z;
    int color;
}               t_voxel;

typedef struct  s_pixel
{
    int x;
    int y;
    int color;
}               t_pixel;

typedef struct  s_map_tools
{
    int     fd;
    int     columns;
    int     rows;
    t_voxel **map;
}               t_map_tools;

/* from utils.c */
void    diy_pixel_put(t_img_data *data, int x, int y, int color);
t_pixel voxtopix(t_voxel source);
/* from main.c */
int     clean_exit(unsigned char error_code, t_mlx_data *mlx, t_map_tools *mtools);
int     keypress(int keycode, t_mlx_vars *vars);
/* from read.c*/

/* from store.c */

/* from draw.c */
int    draw_line_low(t_img_data *data, t_pixel a, t_pixel b);
int    draw_line_high(t_img_data *data, t_pixel a, t_pixel b);
void    draw_map(t_map_tools *mtools, t_img_data *data);
/* from color.C */
int     create_trgb(int t, int r, int g, int b);
int	    get_t(int trgb);
int     get_r(int trgb);
int     get_g(int trgb);
int     get_b(int trgb);

#endif