/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:18:36 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:18:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Print the usage
 * @param params
 * @param y
 * @param label
 * @param key
 */
static void	print_usage(t_param *params, int y, char *label, char *key)
{
	mlx_string_put(params->mlx_ptr, params->win_ptr, 25, y, WHITE, label);
	mlx_string_put(params->mlx_ptr, params->win_ptr, 200, y, WHITE, key);
}

/**
 * Print the menu
 * @param params
 */
void	print_menu(t_param *params)
{
	mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 5, WHITE, "Usage");
	print_usage(params, 35, "Move", "left up down right(a w s d)");
	print_usage(params, 55, "Zoom in/out", "scroll down/scroll up(+ -)");
	print_usage(params, 75, "Projection", "p");
	print_usage(params, 95, "Z-height", "z x");
	print_usage(params, 115, "Reset", "space");
	print_usage(params, 135, "Quit", "ESC");
}
