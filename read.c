/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:25:28 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/20 16:50:05 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_free(char *line, char **aux)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	if (aux)
	{
		while (aux[i])
		{
			free(aux[i]);
			i++;
		}
	}
	free(aux);
	return (0);
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

int	read_map(t_map_tools *mtools)
/*
** Reads the map line by line, allocating and storing each line as it is read.
** To avoid reading twice, a block of size buff is allocated for the rows of
** the map.
** When needed this block increases and the map is reallocated.
*/
{
	char	*line;
	char	**aux;
	int		buff;

	line = NULL;
	buff = 32;
	mtools->map = malloc(sizeof(t_voxel *) * buff);
	while (get_next_line(mtools->fd, &line))
	{
		if (mtools->rows >= buff)
		{
			buff += 32;
			mtools->map = realloc(mtools->map, sizeof(t_voxel *) * buff);
		}
		mtools->columns = check_line(line, mtools->columns);
		if (mtools->columns < 0)
			return (read_free(line, aux) + 1);
		aux = ft_split(line, ' ');
		mtools->map[mtools->rows] = malloc(sizeof(t_voxel) * mtools->columns);
		if (mtools->map == NULL || mtools->map[mtools->rows] == NULL)
			return (read_free(line, aux) + 1);
		store_map(mtools, aux);
		mtools->rows++;
		read_free(line, aux);
	}
	free(line);
	if (mtools->rows == 0 || mtools->columns == 0)
		return (1);
	return (0);
}
