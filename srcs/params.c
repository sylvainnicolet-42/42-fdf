/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:39:32 by synicole          #+#    #+#             */
/*   Updated: 2023/03/15 10:39:33 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Build the parameters structure
 * @param matrix The matrix of t_dot
 * @return Pointer to the parameters structure
 */
t_param	*params_build(t_dot **matrix)
{
	t_param	*params;
	void	*mlx_ptr;
	void	*win_ptr;

	params = malloc(sizeof(t_param));
	if (!params)
		ft_print_error("Malloc error");
	params->matrix = matrix;
	params->scale = P_SCALE;
	params->z_scale = P_Z_SCALE;
	params->projection = P_PROJECTION;
	params->angle = P_ANGLE;
	params->win_x = P_WIN_X;
	params->win_y = P_WIN_Y;
	params->shift_x = params->win_x / 2;
	params->shift_y = params->win_y / 3;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		ft_print_error("mlx_init error");
	params->mlx_ptr = mlx_ptr;
	win_ptr = mlx_new_window(params->mlx_ptr, params->win_x, params->win_y, "FDF");
	if (!win_ptr)
		ft_print_error("mlx_new_window error");
	params->win_ptr = win_ptr;
	return (params);
}

void	reset_params(t_param *params)
{
	params->scale = P_SCALE;
	params->z_scale = P_Z_SCALE;
	params->projection = P_PROJECTION;
	params->angle = P_ANGLE;
	params->win_x = P_WIN_X;
	params->win_y = P_WIN_Y;
	params->shift_x = params->win_x / 2;
	params->shift_y = params->win_y / 3;
}
