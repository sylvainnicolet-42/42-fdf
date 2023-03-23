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

/**
 * Check if the button is one of the buttons we want to handle
 * @param key
 * @return int
 */
static int	is_button(int key)
{
	return (key == MOUSE_SCROLL_DOWN || key == MOUSE_SCROLL_UP);
}

/**
 * Update the params according to the button pressed
 * @param button
 * @param params
 */
static void	update_params(int button, t_param *params)
{
	if (button == MOUSE_SCROLL_DOWN)
		params->scale += 3;
	if (button == MOUSE_SCROLL_UP)
		params->scale -= 3;
}

/**
 * Handle button press
 * @param button
 * @param params
 * @return int
 */
int	mouse_hook(int button, int x, int y, t_param *params)
{
	(void) x;
	(void) y;
	if (is_button(button))
	{
		update_params(button, params);
		print_menu(params);
		image_refresh(params);
	}
	return (0);
}
