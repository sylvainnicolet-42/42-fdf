/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:03:39 by synicole          #+#    #+#             */
/*   Updated: 2023/03/10 19:03:41 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	is_key(int key)
{
	return (key == MOUSE_SCROLL_DOWN || key == MOUSE_SCROLL_UP);
}

int	mouse_hook(int button, int x, int y, t_param *params)
{
	(void) x;
	(void) y;

	if (is_key(button))
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		if (button == MOUSE_SCROLL_DOWN)
			params->scale += 3;
		if (button == MOUSE_SCROLL_UP)
			params->scale -= 3;
		print_menu(params);
		draw(params->matrix, params);
	}
	return (0);
}