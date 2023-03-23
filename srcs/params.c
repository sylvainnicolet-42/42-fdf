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

static void	create_mlx(t_param *params)
{
	params->mlx_ptr = mlx_init();
	if (!params->mlx_ptr)
		ft_print_error("mlx_init error");
	params->win_ptr = mlx_new_window(
			params->mlx_ptr, params->win_x, params->win_y, "FDF");
	if (!params->win_ptr)
		ft_print_error("mlx_new_window error");
}

static void	create_img(t_param *params)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		ft_print_error("Malloc error");
	img->img_ptr = mlx_new_image(
			params->mlx_ptr, params->win_x, params->win_y);
	if (!img->img_ptr)
		ft_print_error("mlx_new_image error");
	img->addr = mlx_get_data_addr(
			img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	params->img = img;
}

/**
 * Build the parameters structure
 * @param matrix The matrix of t_dot
 * @return Pointer to the parameters structure
 */
t_param	*params_build(t_dot **matrix)
{
	t_param	*params;

	params = malloc(sizeof(t_param));
	if (!params)
		ft_print_error("Malloc error");
	params->matrix = matrix;
	reset_params(params);
	create_mlx(params);
	create_img(params);
	return (params);
}

/**
 * Reset the parameters to default
 * @param params
 */
void	reset_params(t_param *params)
{
	params->scale = P_SCALE;
	params->z_scale = P_Z_SCALE;
	params->projection = P_PROJECTION;
	params->win_x = P_WIN_X;
	params->win_y = P_WIN_Y;
	params->shift_x = params->win_x / 2;
	params->shift_y = P_POS_Y;
	params->color = P_COLOR;
	params->angle = P_ANGLE * M_PI / 180;
	params->alpha = P_ANGLE * M_PI / 180;
	params->beta = 0;
	params->teta = 0;
}

/**
 * Refresh the parameters
 * @param a
 * @param b
 * @param params
 */
void	refresh_params(t_dot *a, t_dot *b, t_param *params)
{
	zoom(a, b, params);
	if (params->projection == VIEW_ISO)
	{
		x_rotation(a, b, params->alpha);
		y_rotation(a, b, params->beta);
		z_rotation(a, b, params->teta);
		isometric(a, b, params);
	}
	shifting(a, b, params);
}
