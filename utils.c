/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/18 03:16:56 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx.mlx_ptr, vars->mlx.win);
	exit(EXIT_SUCCESS);
	return(0);
}

void	clear_screen(t_mlx_data *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->img_height)
	{
		x = 0;
		while (x < mlx->img_width)
		{
			diy_pixel_put(mlx, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	init_vars(t_mlx_data *mlx, t_map_tools *mtools)
{
	mlx->img_width = 1920;
	mlx->img_height = 1080;
	mtools->columns = 0;
	mtools->rows = 0;
	mtools->x_offset = mlx->img_width / 2;
	mtools->y_offset = mlx->img_height / 3;
	mtools->z_max = 0;
}

void	diy_pixel_put(t_mlx_data *mlx, int x, int y, int color)
/*
**                   _______
**             _____/       \_____
**             |  _     ___   _   ||
**             | | \     |   | \  ||
**             | |  |    |   |  | ||
**             | |_/     |   |_/  ||
**             | | \     |   |    ||
**             | |  \    |   |    ||
**             | |   \. _|_. | .  ||
**             |                  ||
**             |    seg fault     ||
**             |                  ||
**     *       | *   **    * **   |**      **
**      \))ejm97/.,(//,,..,,\||(,,.,\\,.((//
**	Here lies the fucking segfault that ruined the project
*/
{
	char	*dst;

	if ((x <= mlx->img_width && x >= 0) && (y <= mlx->img_height && y >= 0))
	{
		dst = mlx->img.addr + (y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_pixel	voxtopix(t_voxel source, t_map_tools *mtools)
/*
** The 3D point (voxel) gets converted to it's 2D isometric representation
** (pixel) by rotating the map 45º and reducing the height by half
*/
{
	t_pixel	dst;
	int 	xy_scale;
	int		z_scale;

	xy_scale = 10;
	z_scale = xy_scale;
	while (mtools->z_max * z_scale > mtools->y_offset)
		z_scale /= 2;
	dst.x = mtools->x_offset + (source.x - source.y) * xy_scale;
	dst.y =  mtools->y_offset + ((source.x + source.y) * xy_scale) / 2 - (source.z * z_scale);
	dst.color = source.color;
	return (dst);
}