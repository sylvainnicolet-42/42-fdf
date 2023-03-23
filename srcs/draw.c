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

void	img_pix_put(t_param *params, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < params->win_x && y >= 0 && y < params->win_y)
	{
		pixel = params->img->addr
			+ (y * params->img->line_length
				+ x * (params->img->bits_per_pixel / 8));
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
		img_pix_put(params, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
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
	mlx_put_image_to_window(
		params->mlx_ptr, params->win_ptr, params->img->img_ptr, 0, 0);
	print_menu(params);
}
