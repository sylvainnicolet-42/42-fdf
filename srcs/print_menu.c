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

static void	print_usage(t_param *params, int y, char *label, char *key)
{
	mlx_string_put(params->mlx_ptr, params->win_ptr, 25, y, WHITE, label);
	mlx_string_put(params->mlx_ptr, params->win_ptr, 200, y, WHITE, key);
}

void	print_menu(t_param *params)
{
	mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 5, WHITE, "Usage");
	print_usage(params, 35, "Move", "left up down right");
	print_usage(params, 55, "Move", "a w s d");
	print_usage(params, 75, "Zoom in", "scroll down");
	print_usage(params, 95, "Zoom out", "scroll up");
}
