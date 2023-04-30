/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:50:30 by mpascual          #+#    #+#             */
/*   Updated: 2023/04/30 18:55:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void clean_exit(unsigned char error_code, t_mlx_data *mlx, t_map_tools *mtools)
/*
**  O   O   O   O   O   O   O   O   error_code
**  ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃
**  ┃   ┃   ┃   ┃   ┃   ┃   ┃   ╹━━━> output error_message
**  ┃   ┃   ┃   ┃   ┃   ┃   ╹━━━━━━━> close fd
**  ┃   ┃   ┃   ┃   ┃   ╹━━━━━━━━━━━> destroy window
**  ┃   ┃   ┃   ┃   ╹━━━━━━━━━━━━━━━> free map
*/
{
    if (error_code / 8)
        free_map(mtools);
	if (error_code / 4)
        mlx_destroy_window(mlx->mlx_ptr, mlx->win);
    if (error_code / 2)
        close(mtools->fd);
    if (error_code % 2)
    {
        ft_putstr_fd("Error\n", 2);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int keypress(int keycode, t_vars *vars)
/*
** Detect a key being pressed and calls the necesary functions before
** rendering and updating the frame
*/
{
	ft_printf("keycode = %i\n", keycode);
    if (keycode == KEY_ESCAPE)
        clean_exit(0b1110, &vars->mlx, &vars->mtools);
	/*
    else if (keycode == KEY_ARROW_UP || keycode == KEY_ARROW_DOWN ||
            keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
        move_map(keycode, &vars->mtools, &vars->mlx);
	*/
	draw_map(&vars->mtools, &vars->mlx);
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win,
						 vars->mlx.img.img_ptr, 0, 0);
    return (0);
}

int main(int argc, char **argv)
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
    if (read_map(&vars.mtools) == -1)
        clean_exit(0b0011, &vars.mlx, &vars.mtools);
    vars.mlx.mlx_ptr = mlx_init();
    vars.mlx.win = mlx_new_window(vars.mlx.mlx_ptr, 1920, 1080, "FDF");
	vars.mlx.img.img_ptr = mlx_new_image(vars.mlx.mlx_ptr,
						 vars.mlx.img_width, vars.mlx.img_height);
    mlx_key_hook(vars.mlx.win, keypress, &vars);
	mlx_hook(vars.mlx.win, 17, 0L, close_win, &vars);
    mlx_loop(vars.mlx.mlx_ptr);
    return (0);
}