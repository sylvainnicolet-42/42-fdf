/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_refresh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:48:29 by synicole          #+#    #+#             */
/*   Updated: 2023/03/23 08:48:30 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	image_refresh(t_param *params)
{
	mlx_destroy_image(params->mlx_ptr, params->img->img_ptr);
	params->img->img_ptr = mlx_new_image(
			params->mlx_ptr, params->win_x, params->win_y);
	params->img->addr = mlx_get_data_addr(
			params->img->img_ptr, &params->img->bits_per_pixel,
			&params->img->line_length, &params->img->endian);
	draw(params);
}
