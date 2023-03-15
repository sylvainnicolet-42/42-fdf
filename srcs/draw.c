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

static void	line(t_dot a, t_dot b, t_param *param)
{
	float	step_x;
	float	step_y;
	float	abs_step_x;
	float	abs_step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
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
	step_x /= max;
	step_y /= max;
	if (b.z || a.z)
		color = 0xfc0345;
	else
		color = 0xBBFAFF;
	if (b.z != a.z)
		color = 0xfc031c;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

/**
 * Draw the matrix of t_dot
 * @param params
 */
void	draw(t_param *params)
{
	int	y;
	int	x;

	print_menu(params);
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
}
