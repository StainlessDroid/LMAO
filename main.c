/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:50:30 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/20 17:49:59 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_mlx_data *mlx, t_map_tools *mtools)
/*
** Create an mlx instance with a window and fitting image
** Set initial values for the variables of the map position and scale
*/
{
	mlx->img_width = 1920;
	mlx->img_height = 1080;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, mlx->img_width,
			mlx->img_height, "FDF");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->img_width,
			mlx->img_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	mtools->columns = 0;
	mtools->rows = 0;
	mtools->x_offset = mlx->img_width / 2;
	mtools->y_offset = mlx->img_height / 4;
	mtools->z_max = 0;
	mtools->xy_scale = 10;
}

void	set_scale(t_mlx_data *mlx, t_map_tools *mtools)
/* Set the initial scale of the map to match the size of the screen */
{
	if (mtools->columns > mtools->rows)
		mtools->xy_scale = mlx->img_width / (mtools->columns * 2);
	else
		mtools->xy_scale = mlx->img_height / (mtools->rows * 2);
	mtools->z_scale = mtools->xy_scale;
	while (mtools->z_max * mtools->z_scale > mtools->y_offset)
		mtools->z_scale /= 2;
}

int	keypress(int keycode, t_vars *vars)
/*
** Detects a key being pressed and change the necesary variables before
** cleaning, rendering and updating the frame
*/
{
	if (keycode == KEY_ESCAPE)
		clean_exit(0b1110, &vars->mlx, &vars->mtools);
	if (keycode == KEY_ARROW_DOWN)
		vars->mtools.y_offset += 50;
	if (keycode == KEY_ARROW_UP)
		vars->mtools.y_offset -= 50;
	if (keycode == KEY_ARROW_RIGHT)
		vars->mtools.x_offset += 50;
	if (keycode == KEY_ARROW_LEFT)
		vars->mtools.x_offset -= 50;
	if (keycode == KEY_PAGEUP)
		vars->mtools.z_scale *= 1.25;
	if (keycode == KEY_PAGEDOWN)
		vars->mtools.z_scale *= 0.75;
	if (keycode == KEY_RBRACKET)
		vars->mtools.xy_scale ++;
	if (keycode == KEY_SLASH)
		vars->mtools.xy_scale --;
	clear_screen(&vars->mlx);
	draw_map(&vars->mtools, &vars->mlx);
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win, vars->mlx.img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
/*
** READS FILE ➡️ SET VARIABLES ➡️ DRAW MAP ➡️ HOOK KEYPRESS ➡️ CHANGE VARIABLES ⬇
**								⬆		⬅			   ⬅				  ⬅
*/
{
	t_vars	vars;

	if (argc != 2)
		clean_exit(0b0001, NULL, NULL);
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
	{
		vars.mtools.fd = open(argv[1], O_RDONLY);
		if (vars.mtools.fd == -1)
			clean_exit(0b0001, NULL, NULL);
	}
	else
		clean_exit(0b0011, NULL, &vars.mtools);
	init_vars(&vars.mlx, &vars.mtools);
	if (read_map(&vars.mtools))
		clean_exit(0b0011, &vars.mlx, &vars.mtools);
	set_scale(&vars.mlx, &vars.mtools);
	draw_map(&vars.mtools, &vars.mlx);
	mlx_put_image_to_window(vars.mlx.mlx_ptr, vars.mlx.win, vars.mlx.img.img_ptr, 0, 0);
	mlx_hook(vars.mlx.win, 2, 1L>>0, keypress, &vars);
	mlx_hook(vars.mlx.win, 17, 0L, close_win, &vars);
	mlx_loop(vars.mlx.mlx_ptr);
	return (0);
}
