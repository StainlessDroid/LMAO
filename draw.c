/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:10:56 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/20 13:36:26 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** I used the Bresenham's line algorithm 
** https://wikipedia.org/wiki/Bresenham's_line_algorithm
**  Two different functions are needed for lines with (-1 < slope < 1) (low)
**  or (-1 > slope || slope > 1) (high)
*/
int	draw_line_low(t_mlx_data *mlx, t_pixel a, t_pixel b)
{
	int	dx, dy;
	int	x, y;
	int	dif;
	int	yi;

	dx = b.x - a.x;
	dy = b.y - a.y;
	yi = 1;
	if (dy < 0)
	{
		dy = -dy;
		yi = -1;
	}
	dif = (2 * dy) - dx;
	y = a.y;
	x = a.x;
	while (x < b.x)
	{
		diy_pixel_put(mlx, x, y, b.color);
		if (dif > 0)
		{
			y += yi;
			dif = dif + 2 * (dy - dx);
		}
		else
			dif = dif + 2 * dy;
		x++;
	}
	return (0);
}

int	draw_line_high(t_mlx_data *mlx, t_pixel a, t_pixel b)
{
	int	dx, dy;
	int	x, y;
	int	dif;
	int	xi;

	dx = b.x - a.x;
	dy = b.y - a.y;
	xi = 1;
	if (dx < 0)
	{
		dx = -dx;
		xi = -1;
	}
	dif = (2 * dx) - dy;
	y = a.y;
	x = a.x;
	while (y < b.y)
	{
		diy_pixel_put(mlx, x, y, b.color);
		if (dif > 0)
		{
			x += xi;
			dif = dif + 2 * (dx - dy);
		}
		else
			dif = dif + 2 * dx;
		y++;
	}
	return (0);
}

void	draw_line(t_mlx_data *mlx, t_pixel a, t_pixel b)
/*
** Calculate the slope between the two points
** and call each function accordingly.
** Swap the points if b > a to draw the lines always in the same +direction
*/
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
			draw_line_low(mlx, b, a);
		else
			draw_line_low(mlx, a, b);
	}
	else
	{
		if (a.y > b.y)
			draw_line_high(mlx, b, a);
		else
			draw_line_high(mlx, a, b);
	}
}

void	draw_map(t_map_tools *mtools, t_mlx_data *mlx)
/*
** Draw a line from the current point to the next in the x and y axes
** and render the image every time a line is written
** Do this for every point in the map except the last ones
*/
{
	t_pixel	point_a;
	t_pixel	point_b;
	int		y;
	int		x;

	y = 0;
	while (y < mtools->rows)
	{
		x = 0;
		while (x < mtools->columns)
		{
			point_a = voxtopix(mtools->map[y][x], mtools);
			if (x < mtools->columns - 1)
			{
				point_b = voxtopix(mtools->map[y][x + 1], mtools);
				draw_line(mlx, point_a, point_b);
			}
			if (y < mtools->rows - 1)
			{
				point_b = voxtopix(mtools->map[y + 1][x], mtools);
				draw_line(mlx, point_a, point_b);
			}
			x++;
		}
		y++;
	}
}
