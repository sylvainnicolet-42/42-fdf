/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:18:09 by synicole          #+#    #+#             */
/*   Updated: 2023/02/08 22:18:11 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Refresh the zoom
 * @param a
 * @param b
 * @param params
 */
void	zoom(t_dot *a, t_dot *b, t_param *params)
{
	a->x *= params->scale;
	a->y *= params->scale;
	b->x *= params->scale;
	b->y *= params->scale;
	a->z *= params->z_scale;
	b->z *= params->z_scale;
}

/**
 * Refresh the shift
 * @param a
 * @param b
 * @param params
 */
void	shifting(t_dot *a, t_dot *b, t_param *params)
{
	a->x += params->shift_x;
	a->y += params->shift_y;
	b->x += params->shift_x;
	b->y += params->shift_y;
}

/**
 * Use isometric view
 * @param a
 * @param b
 * @param params
 */
void	isometric(t_dot *a, t_dot *b, t_param *params)
{
	a->x = (a->x - a->y) * cos(params->angle);
	a->y = (a->x + a->y) * sin(params->angle) - a->z;
	b->x = (b->x - b->y) * cos(params->angle);
	b->y = (b->x + b->y) * sin(params->angle) - b->z;
}