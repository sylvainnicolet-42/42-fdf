/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:05:16 by synicole          #+#    #+#             */
/*   Updated: 2023/03/16 12:05:18 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Set dot color and height
 * @param dot
 * @param matrix
 * @param x
 * @param y
 */
static void	set_dot_color(char **dot, t_dot **matrix, int x, int y)
{
	char	**z;

	z = ft_split(dot[x], ',');
	matrix[y][x].z = ft_atoi(z[0]);
	if (ft_atoi(z[0]) && !z[1])
		matrix[y][x].has_height = 1;
	free(z[0]);
	if (!z[1])
		matrix[y][x].color = 0;
	else if (z[1])
	{
		matrix[y][x].color = ft_hex_to_int(z[1]);
		free(z[1]);
	}
	free(z);
}

/**
 * Set dots for each line of matrix
 * @param line
 * @param matrix
 * @param y
 */
void	matrix_set_dots(char *line, t_dot **matrix, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		set_dot_color(dots, matrix, x, y);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free(dots[x]);
		x++;
	}
	free(dots);
	matrix[y][x - 1].is_last = 1;
}
