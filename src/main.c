/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:50:30 by mpascual          #+#    #+#             */
/*   Updated: 2023/04/25 19:03:06 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int clean_exit(unsigned char error_code, t_mlx_data *mlx, t_map_tools *mtools)
/*
**  O   O   O   O   O   O   O   O   error_code
**  ┃   ┃   ┃   ┃   ┃   ┃   ┃   ┃
**  ┃   ┃   ┃   ┃   ┃   ┃   ┃   ╹━━━> output error_message
**  ┃   ┃   ┃   ┃   ┃   ┃   ╹━━━━━━━> close fd
**  ┃   ┃   ┃   ┃   ┃   ╹━━━━━━━━━━━> destroy window
**  ┃   ┃   ┃   ┃   ╹━━━━━━━━━━━━━━━> free map
*/
{
    if (error_code % 4)
        close(mtools->fd);
    if (error_code % 8)
        mlx_destroy_window(mlx->mlx_ptr, mlx->win);
    if (error_code % 16)
        free_map(mtools);
    if (error_code % 2)
    {
        ft_putstr_fd(stderr, "Error\n");
        return (1);
    }
    return (0);
}

int keypress(int keycode, t_mlx_data *mlx, t_map_tools *mtools)
/*
** Detect a key being pressed and calls the necesary functions before
** rendering and updating the frame
*/
{
    if (keycode == KEY_ESCAPE)
        return(clean_exit(0b1110, mlx, mtools));
    else if (keycode == KEY_ARROW_UP || keycode == KEY_ARROW_DOWN ||
            keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
        move_map(keycode, mtools, mlx);
    return (0);
}

int main(int argc, char **argv)
{
    t_mlx_data  mlx;
    t_map_tools mtools;

    if (argc != 2)
        return (clean_exit(0b0001, t_mlx_data *mlx, t_map_tools *mtools));
    mtools.fd = open(argv[1], O_RDONLY);
    if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) || !fd)
        return(clean_exit(0b0011, t_mlx_data *mlx, t_map_tools *mtools));
    if (!read_map(&mtools))
        return(clean_exit(3))
    mlx.mlx_ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "LMAO");
    mlx_hook(mlx->win, 2, 1L<<0   , keypress, &mlx);
    mlx_loop_hook()
    
    return (0);
}