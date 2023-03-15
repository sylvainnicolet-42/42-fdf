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

static void	zoom(t_dot *a, t_dot *b, t_param *params)
{
	a->x *= params->scale;
	a->y *= params->scale;
	b->x *= params->scale;
	b->y *= params->scale;
	a->z *= params->z_scale;
	b->z *= params->z_scale;
}

static void	shifting(t_dot *a, t_dot *b, t_param *params)
{
	a->x += params->shift_x;
	a->y += params->shift_y;
	b->x += params->shift_x;
	b->y += params->shift_y;
}

//static void	isometric(t_dot *dot, double angle)
//{
//	dot->x = (dot->x - dot->y) * cos(angle);
//	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
//}

static void isometric(t_dot *a, t_dot *b, t_param *params)
{
	a->x = (a->x - a->y) * cos(params->angle);
	a->y = (a->x + a->y) * sin(params->angle) - a->z;
	b->x = (b->x - b->y) * cos(params->angle);
	b->y = (b->x + b->y) * sin(params->angle) - b->z;
}

void	set_param(t_dot *a, t_dot *b, t_param *params)
{
	zoom(a, b, params);
	if (params->projection == VIEW_ISO)
		isometric(a, b, params);
	shifting(a, b, params);
//	if (params->is_isometric)
//	{
//		isometric(a, params->angle);
//		isometric(b, params->angle);
//	}
}
