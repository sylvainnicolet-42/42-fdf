/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:12:15 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:12:17 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Get color of points with z value
 * @param params
 */
static int	get_color_from_params(t_param *params)
{
	if (params->color == P_BLACK)
		return (BLACK);
	else if (params->color == P_WHITE)
		return (WHITE);
	else if (params->color == P_RED)
		return (RED);
	else if (params->color == P_GREEN)
		return (GREEN);
	else if (params->color == P_BLUE)
		return (BLUE);
	else if (params->color == P_YELLOW)
		return (YELLOW);
	else if (params->color == P_PINK)
		return (PINK);
	else if (params->color == P_CYAN)
		return (CYAN);
	else if (params->color == P_ORANGE)
		return (ORANGE);
	else
		return (P_COLOR);
}

/**
 * Set the color of the line
 * @param a t_dot
 * @param b t_dot
 * @return int color
 */
static int	get_color(t_dot a, t_dot b, t_param *params)
{
	(void) params;
	if (a.color)
		return (a.color);
	else if (b.color)
		return (b.color);
	if (a.has_height == 1 || b.has_height == 1)
		return (get_color_from_params(params));
	return (P_COLOR_GRID);
}

/**
 * Get the max
 * @param step_x
 * @param step_y
 * @return float
 */
static float	get_max(float step_x, float step_y)
{
	float	abs_step_x;
	float	abs_step_y;
	float	max;

	if (step_x < 0)
		abs_step_x = -step_x;
	else
		abs_step_x = step_x;
	if (step_y < 0)
		abs_step_y = -step_y;
	else
		abs_step_y = step_y;
	if (abs_step_x > abs_step_y)
		max = abs_step_x;
	else
		max = abs_step_y;
	return (max);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < 800 && y >= 0 && y < 800)
	{
		pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(int *)pixel = color;
	}
}

/**
 * Draw a line between two points using Bresenham's line algorithm
 * @param a t_dot
 * @param b t_dot
 * @param param
 */
static void	line(t_dot a, t_dot b, t_param *params)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	refresh_params(&a, &b, params);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = get_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	color = get_color(a, b, params);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		img_pix_put(params->img, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
//		if (a.x > params->win_x || a.y > params->win_y || a.y < 0 || a.x < 0)
//			break ;
	}
}

/**
 * Draw the matrix of t_dot
 * @param params
 */
void	draw(t_param *params)
{
	int		y;
	int		x;

	y = 0;
	while (params->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (params->matrix[y + 1])
				line(params->matrix[y][x], params->matrix[y + 1][x], params);
			if (!params->matrix[y][x].is_last)
				line(params->matrix[y][x], params->matrix[y][x + 1], params);
			if (params->matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img->img, 0, 0);
//	params->img->addr = mlx_get_data_addr(
//			params->img->img, &params->img->bits_per_pixel, &params->img->line_length, &params->img->endian);
	print_menu(params);
}

void tmp_draw(t_param *params)
{
	mlx_destroy_image(params->mlx_ptr, params->img->img);
//	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	params->img->img = mlx_new_image(params->mlx_ptr, params->win_x, params->win_y);
	params->img->addr = mlx_get_data_addr(params->img->img, &params->img->bits_per_pixel, &params->img->line_length, &params->img->endian);
	draw(params);
}