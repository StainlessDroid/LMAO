/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:25:28 by mpascual          #+#    #+#             */
/*   Updated: 2023/04/29 16:17:02 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int read_free(char *line, char **aux)
{
    int i;

    i = 0;
    free(line);
    if (aux)
    {
        while (aux[i])
        {
            free(aux[i]);
            i++;
        }
        free(aux);
    }
    return (1);
}

static char	*check_point(char *str)
/*
** Parse every point in the map individually
** Returns:	NULL if point is not valid
*/
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str != ' ' && *str != ',' && *str)
	{
		if (*str < '0' || *str > '9')
			return (NULL);
		str++;
	}
	if (*str == ',')
	{
		if (*(str + 1) != '0' || *(str + 2) != 'x')
			return (NULL);
		str += 3;
		while (*str != ' ' && *str)
		{
			if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
				&& (*str < 'A' || *str > 'F'))
				return (NULL);
			str++;
		}
	}
	if (*str == ' ')
		str++;
	return (str);
}

int	check_line(char *line, int columns)
/*
** Parse the current map line and checks for square
** Returns:	number_of_columns if line is valid
**			-1 if line is not valid
*/
{
	int	x;

	x = 0;
	while (*line)
	{
		while (*line == ' ')
			++line;
		line = check_point(line);
		if (line == NULL)
			return (-1);
		else
			x++;
	}
	if (columns != 0 && x != columns)
		return (-1);
	else
		return (x);
}

int read_map(t_map_tools *mtools)
/*
** Problem with memory allocation of the map
*/
{
    char    *line;
    char    **aux;

    line = NULL;
    mtools->rows = 0;
    mtools->columns = 0;
    while (get_next_line(mtools->fd, &line))
    {
        mtools->columns = check_line(line, mtools->columns);
        if (mtools->columns < 0)
            return (read_free(line, NULL));
        aux = ft_split(line, ' ');
        if (mtools->rows == 0)
            mtools->map = malloc(sizeof(t_voxel*));
        mtools->map[mtools->rows] = realloc(mtools->map[mtools->rows], sizeof(t_voxel) * mtools->columns);
		if (mtools->map == NULL)
			clean_exit(0b1011, NULL, mtools);
        store_map(mtools, aux);
        mtools->rows++;
    }
	if (mtools->rows == 0 || mtools->columns == 0)
		return (1);
	read_free(line, aux);
    return(0);
}
