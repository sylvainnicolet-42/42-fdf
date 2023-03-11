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

# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)

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

enum e_color
{
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	YELLOW = 0xFFFF00,
	PINK = 0xFF00FF,
	CYAN = 0x00FFFF,
	ORANGE = 0xFFA500,
};

enum e_key
{
	KEY_ESC = 53,
	KEY_ARROW_LEFT = 123,
	KEY_ARROW_RIGHT = 124,
	KEY_ARROW_DOWN = 125,
	KEY_ARROW_UP = 126,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
};

enum e_mouse
{
	MOUSE_SCROLL_DOWN = 4,
	MOUSE_SCROLL_UP = 5
};

enum e_xcode_event
{
	ON_DESTROY = 17
};

enum e_xcode_mask
{
	KEY_PRESS_MASK = 2,
};

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
}	t_dot;

typedef struct s_param
{
	t_dot	**matrix;
	int		scale;
	int		z_scale;
	int		shift_x;
	int		shift_y;
	int		is_isometric;
	double	angle;
	int		win_x;
	int		win_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_param;

t_dot	**read_map(char *file_path);
t_dot	**matrix_create(char *file_path);
void	matrix_display(t_dot **matrix);
void	matrix_build(t_dot **matrix, char *file_path);
void	matrix_clear(t_dot **matrix);
void	draw(t_param *params);
void	print_menu(t_param *params);
void	set_param(t_dot *a, t_dot *b, t_param *params);
void	isometric(t_dot *dot, double angle);
int		key_hook(int key, t_param *params);
void	new_window(int key, t_dot **matrix, t_param *params);
int 	mouse_hook(int button, int x, int y, t_param *params);
int		fdf_close(t_param *params);

/**
 * Print in console
*/
void	ft_print_success(char *str);
void	ft_print_error(char *str);

#endif