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

void	matrix_display(t_dot **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j].is_last == 0)
		{
			printf("x = %f, y = %f, z = %f\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);
			j++;
		}
		printf("x = %f, y = %f, z = %f\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);
		i++;
	}
}

static int	matrix_set_dots(char *line, t_dot **matrix, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix[y][x].z = ft_atoi(dots[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free(dots[x]);
		x++;
	}
	free(dots);
	matrix[y][x -1].is_last = 1;
	return (x);
}

static int	matrix_nb_x(int fd)
{
	int 	nb_x;
	char	*line;

	line = get_next_line(fd);
	nb_x = ft_wdcounter(line, ' ');
	free(line);
	return (nb_x);
}

static int	matrix_nb_y(int fd)
{
	int 	nb_y;
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
	printf("x = %d, y = %d\n", x, y);
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
	matrix[y] = NULL;
	close(fd);
}