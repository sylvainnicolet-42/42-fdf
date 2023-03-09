/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:39:54 by synicole          #+#    #+#             */
/*   Updated: 2023/02/01 20:39:56 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# define BUFFER_SIZE 10
//# define PRM matrix[0][0]
//# define MAX(A, B) (A > B ? A : B)
//# define MIN(A, B) (A > B ? B : A)

/**
 * Libraries
*/
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

/**
 * Get next line
*/
char	*get_next_line(int fd);
char	*gnl_get_line(char **stash);
void	gnl_read_line(int fd, char *buffer, char **stash);
size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(char *s, int c);

int		ft_wdcounter(char const *str, char c);

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
}	t_dot;

t_dot	**read_map(char *file_path);
t_dot	**matrix_create(char *file_path);
void	matrix_display(t_dot **matrix);
void	matrix_build(t_dot **matrix, char *file_path);
void	matrix_clear(t_dot **matrix);

//void	isometric(t_dot *dot, double angle);
//void	draw(t_dot **matrix);
//int		deal_key(int key, t_dot **matrix);
//void	set_param(t_dot *a, t_dot *b, t_dot *param);
//void	print_menu(t_dot param);
//void	new_window(int key, t_dot **matrix);

/**
 * Print in console
*/
void	ft_print_success(char *str);
void	ft_print_error(char *str);

#endif