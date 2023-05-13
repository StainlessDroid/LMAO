/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/14 01:05:32 by mpascual         ###   ########.fr       */
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
	mlx->img_width = 1920;
	mlx->img_height = 1080;
	mtools->columns = 0;
	mtools->rows = 0;
}

void	diy_pixel_put(t_mlx_data *mlx, int x, int y, int color)
{
	char	*dst;

	if (x <= mlx->img_width && y <= mlx->img_height)
	{
		dst = mlx->img.addr + (y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	else
		ft_putstr("Out of the screen\n");
}

t_pixel	voxtopix(t_voxel source, t_mlx_data *mlx)
/*
** The 3D point (voxel) gets converted to it's 2D isometric representation
** (pixel) by rotating the map 45º and reducing the height by half
*/
{
	t_pixel	dst;
	int 	spacing;
	int		x_offset;
	int		y_offset;

	spacing = 10;
	x_offset = mlx->img_width / 2;
	y_offset = (mlx->img_height / 3); 
	dst.x = x_offset + (source.x - source.y) * spacing;
	dst.y =  y_offset + ((source.x + source.y) * spacing) / 2 - (source.z * spacing / 2);
	dst.color = source.color;
	return (dst);
}