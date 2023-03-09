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
int		ft_read_from_buff(char **current_buff, int fd);
char	*ft_get_line(char *current_buff);
char	*ft_init_new_buff(char *current_buff);

char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
void	*ft_gnl_calloc(size_t nmemb, size_t size);
char	*ft_gnl_substr(char const *s, size_t len);
size_t	ft_gnl_strlen(char const *str);
size_t	ft_gnl_strlcat(char *dst, const char *src, size_t size);

int		ft_wdcounter(char const *str, char c);

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
}	t_dot;

t_dot	**read_map(char *file_name);
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