/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:44:04 by mapascua          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:51 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx.mlx_ptr, vars->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	clean_exit(char code, t_mlx_data *mlx, t_map_tools *mtools, char *msg)
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
	if (code / 8)
		free_map(mtools);
	if (code / 4)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	}
	if (code / 2)
		close(mtools->fd);
	if (code % 2)
	{
		ft_putstr_fd("Error\n", 2);
		if (msg)
			ft_putstr_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	diy_pixel_put(t_mlx_data *mlx, int x, int y, int color)
/*
** Check that the pixel is within the screen boundries before adding
** the info to the image
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
