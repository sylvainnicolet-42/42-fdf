/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:20:52 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:20:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_param *params)
{
	if (key == 24 || key == 69)
		params->scale += 3;
	if (key == 27 || key == 78)
		params->scale -= 3;
	if (key == 91 || key == 28)
		params->z_scale += 1;
	if (key == 84 || key == 19)
		params->z_scale -= 1;
	if (key == '~')
		params->shift_y -= 10;
	if (key == '}')
		params->shift_y += 10;
	if (key == '{')
		params->shift_x -= 10;
	if (key == '|')
		params->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		params->is_isometric = (params->is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		params->angle += 0.05;
	if (key == 88 || key == 22)
		params->angle -= 0.05;
}

int	deal_key(int key, t_dot **matrix, t_param *params)
{
	if (is_key(key))
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		do_key(key, params);
		print_menu(params);
		draw(matrix, params);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix, params);
	if (key == '5')
	{
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
