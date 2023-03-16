/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:15:55 by synicole          #+#    #+#             */
/*   Updated: 2023/03/09 14:15:57 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Get number of columns in matrix
 * @param fd
 * @return Integer number of columns
 */
static int	matrix_nb_x(int fd)
{
	int		nb_x;
	char	*line;

	line = get_next_line(fd);
	nb_x = ft_wdcounter(line, ' ');
	free(line);
	return (nb_x);
}

/**
 * Get number of rows in matrix
 * @param fd
 * @return Integer number of rows
 */
static int	matrix_nb_y(int fd)
{
	int		nb_y;
	char	*line;

	nb_y = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		nb_y++;
	}
	return (nb_y);
}

/**
 * Create and allocate memory for new matrix from file
 * @param file_path
 * @return t_dot** Matrix of t_dot
 */
t_dot	**matrix_create(char *file_path)
{
	t_dot	**new_matrix;
	int		x;
	int		y;
	int		fd;

	fd = open(file_path, O_RDONLY, 0);
	if (fd <= 0)
		ft_print_error("File does not exist");
	x = matrix_nb_x(fd);
	y = matrix_nb_y(fd);
	new_matrix = malloc(sizeof(t_dot *) * (y + 1));
	if (!new_matrix)
		ft_print_error("Malloc error");
	while (y >= 0)
	{
		new_matrix[y] = malloc(sizeof(t_dot) * (x + 1));
		if (!new_matrix[y])
			ft_print_error("Malloc error");
		y--;
	}
	close(fd);
	return (new_matrix);
}

/**
 * Build matrix from file
 * @param matrix
 * @param file_path
 */
void	matrix_build(t_dot **matrix, char *file_path)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_path, O_RDONLY, 0);
	if (fd <= 0)
		ft_print_error("File does not exist");
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		matrix_set_dots(line, matrix, y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(matrix[y]);
	matrix[y] = NULL;
	close(fd);
}
