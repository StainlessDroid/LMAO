/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/04/30 18:53:37 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx.mlx_ptr, vars->mlx.win);
	exit(EXIT_SUCCESS);
	return(0);
}

void	init_vars(t_mlx_data *mlx, t_map_tools *mtools)
{
	mlx->img_height = 1080;
	mlx->img_width = 1920;
	mtools->columns = 0;
	mtools->rows = 0;
}

void	diy_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_pixel	voxtopix(t_voxel source)
/*
** The 3D point (voxel) gets converted to it's 2D isometric representation
** (pixel) by rotating the map 45º and reducing the height by half
*/
{
	t_pixel	dst;

	dst.x = 1024/2 + (source.x - source.y) * 12;
	dst.y = 300 + ((source.x + source.y) * 12) / 2 - (source.z * 6);
	dst.color = source.color;
	return (dst);
}