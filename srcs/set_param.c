/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:18:09 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:18:11 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(t_dot *a, t_dot *b, t_param *params)
{
	a->x *= params->scale;
	a->y *= params->scale;
	b->x *= params->scale;
	b->y *= params->scale;
	a->z *= params->z_scale;
	b->z *= params->z_scale;
}

void	set_param(t_dot *a, t_dot *b, t_param *params)
{
	zoom(a, b, params);
	if (params->is_isometric)
	{
		isometric(a, params->angle);
		isometric(b, params->angle);
	}
	a->x += params->shift_x;
	a->y += params->shift_y;
	b->x += params->shift_x;
	b->y += params->shift_y;
}
