/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:44:04 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/30 15:40:32 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx.mlx_ptr, vars->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	clean_exit(char error_code, t_mlx_data *mlx, t_map_tools *mtools)
/*
** Reads the last 4 bits of the char (1st argument) as an error code 
**  O   O   O   O	  error_code
**  ┃   ┃   ┃   ┃
**  ┃   ┃   ┃   ╹━━━> output error_message
**  ┃   ┃   ╹━━━━━━━> close fd
**  ┃   ╹━━━━━━━━━━━> destroy window
**  ╹━━━━━━━━━━━━━━━> free map
*/
{
	if (error_code / 8)
		free_map(mtools);
	if (error_code / 4)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	}
	if (error_code / 2)
		close(mtools->fd);
	if (error_code % 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
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
**             |      bonus       ||
**             |                  ||
**     *       | *   **    * **   |**      **
**      \))ejm97/.,(//,,..,,\||(,,.,\\,.((//
**			 FUCK YOU RANDOM SEGFAULT!!
*/
{
	char	*dst;

	if ((x < mlx->img_width && x >= 0) && (y < mlx->img_height && y >= 0))
	{
		dst = mlx->img.addr + (y * mlx->img.line_length + x
				* (mlx->img.bits_per_pixel / 8));
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

	dst.x = mtools->x_offset + (source.x - source.y) * mtools->xy_scale;
	dst.y = mtools->y_offset + ((source.x + source.y) * mtools->xy_scale) / 2
		- (source.z * mtools->z_scale);
	dst.color = source.color;
	return (dst);
}
