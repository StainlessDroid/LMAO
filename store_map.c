/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:46:09 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/18 02:43:38 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    free_map(t_map_tools *mtools)
{
    int i;

    i = 0;
    while (i < mtools->rows)
    {
        free(mtools->map[i]);
        i++;
    }
    free(mtools->map);
}

int store_map(t_map_tools *mtools, char **aux)
/*
** stores the current line of the map at reading time
*/
{
    int x;
	int i;
    int color;

    x = 0;
    while (aux[x] && x <= mtools->columns)
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
