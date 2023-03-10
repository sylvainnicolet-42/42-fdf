/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:21:34 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:21:35 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_win_size(int key, t_param *params)
{
	if ((key == 0 && params->win_y <= 500) || (key == 6 && params->win_x <= 500))
		return (1);
	if ((key == 1 && params->win_y > 1000) || (key == 7 && params->win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_param *params)
{
	static int old_x;
	static int old_y;

	if (params->win_x != 2560)
	{
		old_x = params->win_x;
		old_y = params->win_y;
	}
	params->win_x = (params->win_x == 2560) ? old_x : 2560;
	params->win_y = (params->win_y == 1400) ? old_y : 1400;
}

void	change_window_size(int key, t_param *params)
{
	if (check_win_size(key, params))
		return ;
	if (key == 6)
		params->win_x -= 100;
	if (key == 7)
		params->win_x += 100;
	if (key == 0)
		params->win_y -= 100;
	if (key == 1)
		params->win_y += 100;
	if (key == 3)
		full_screen(params);
}

void	new_window(int key, t_dot **matrix, t_param *params)
{
	change_window_size(key, params);
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, params->win_x, params->win_y, "FDF");
	params->shift_x = params->win_x / 3;
	params->shift_y = params->win_y / 3;
	draw(matrix, params);
	mlx_key_hook(params->win_ptr, deal_key, matrix);
	mlx_loop(params->mlx_ptr);
}
