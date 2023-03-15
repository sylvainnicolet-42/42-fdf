/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:20:52 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:20:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Check if the key is one of the keys we want to handle
 * @param key
 * @return int
 */
static int	is_key(int key)
{
	return (key == KEY_ESC || key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT
		|| key == KEY_ARROW_DOWN || key == KEY_ARROW_UP || key == KEY_A
		|| key == KEY_S || key == KEY_D || key == KEY_W || key == KEY_P
		|| key == KEY_E || key == KEY_R
	);
}

/**
 * Update the params according to the key pressed
 * @param key
 * @param params
 */
static void	update_params(int key, t_param *params)
{
	if (key == KEY_ESC)
		fdf_close(params);
	if (key == KEY_ARROW_LEFT || key == KEY_A)
		params->shift_x += 10;
	if (key == KEY_ARROW_RIGHT || key == KEY_D)
		params->shift_x -= 10;
	if (key == KEY_ARROW_DOWN || key == KEY_S)
		params->shift_y -= 10;
	if (key == KEY_ARROW_UP || key == KEY_W)
		params->shift_y += 10;
	if (key == KEY_P)
	{
		if (params->projection == VIEW_TOP)
			params->projection = 0;
		else
			params->projection++;
	}
	if (key == KEY_E)
		params->angle += 0.05;
	if (key == KEY_R)
		params->angle -= 0.05;
//	if (key == 91 || key == 28)
//		params->z_scale += 1;
//	if (key == 84 || key == 19)
//		params->z_scale -= 1;
}

/**
 * Handle key press
 * @param key
 * @param params
 * @return int
 */
int	key_hook(int key, t_param *params)
{
	printf("key: %d\n", key);
	if (is_key(key))
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		update_params(key, params);
		print_menu(params);
		draw(params);
	}
	return (0);
}
