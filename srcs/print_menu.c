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

void	print_menu(t_param *params)
{
	char	*menu;

	menu = "MOVE: up, down, left, right";
	mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 5, 0x03fc35, menu);
	menu = "3D/2D MODE: space";
	mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 20, 0x03fc35, menu);
	menu = "ZOOM: +, -";
	mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 35, 0x03fc35, menu);
	menu = "Z-SCALE: 8, 2";
	mlx_string_put(params->mlx_ptr, params->win_ptr, 10, 50, 0x03fc35, menu);
}
