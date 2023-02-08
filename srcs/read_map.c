/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:10 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 14:14:12 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_print_error("file does not exist");
	line = get_next_line(fd);
	x = ft_wdcounter(line, ' ');
	y = 0;
	while (line)
	{
		line = get_next_line(fd);
		y++;
	}
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		get_dots_from_line(line, matrix_of_dots, y++);
		line = get_next_line(fd);
	}
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
