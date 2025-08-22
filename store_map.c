/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:47:25 by mapascua          #+#    #+#             */
/*   Updated: 2025/08/22 15:47:48 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map_tools *mtools)
{
	int	i;

	i = 0;
	while (i < mtools->rows)
	{
		free(mtools->map[i]);
		i++;
	}
	free(mtools->map);
}

int	store_map(t_map_tools *mtools, char **aux)
/* stores the current line of the map as it's readed by gnl and parsed */
{
	int	x;
	int	i;
	int	color;

	x = 0;
	while (aux[x] && x < mtools->columns)
	{
		color = DEFAULT_COLOR;
		mtools->map[mtools->rows][x].x = x;
		mtools->map[mtools->rows][x].y = mtools->rows;
		mtools->map[mtools->rows][x].z = ft_atoi(aux[x]);
		if (mtools->map[mtools->rows][x].z > mtools->z_max)
			mtools->z_max = mtools->map[mtools->rows][x].z;
		if (ft_strchr(aux[x], ','))
		{
			i = 0;
			while (aux[x][i] && aux[x][i] != 'x')
				i++;
			i++;
			color = ft_atoi_base(aux[x] + i, 16);
		}
		mtools->map[mtools->rows][x].color = color;
		x++;
	}
	return (0);
}
