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

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

static void	line(t_dot a, t_dot b, t_param *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

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
