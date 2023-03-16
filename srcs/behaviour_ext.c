/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:02:51 by synicole          #+#    #+#             */
/*   Updated: 2023/03/16 12:02:52 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

/**
 * X rotation
 * @param a
 * @param b
 * @param alpha
 */
void	x_rotation(t_dot *a, t_dot *b, double alpha)
{
	a->y = a->y * cos(alpha) + a->z * sin(alpha);
	a->z = -(a->y) * sin(alpha) + a->z * (cos(alpha));
	b->y = b->y * cos(alpha) + b->z * sin(alpha);
	b->z = -(b->y) * sin(alpha) + b->z * (cos(alpha));
}

/**
 * Y rotation
 * @param a
 * @param b
 * @param beta
 */
void	y_rotation(t_dot *a, t_dot *b, double beta)
{
	a->x = a->x * cos(beta) + a->z * sin(beta);
	a->z = -(a->x) * sin(beta) + a->z * (cos(beta));
	b->x = b->x * cos(beta) + b->z * sin(beta);
	b->z = -(b->x) * sin(beta) + b->z * (cos(beta));
}

/**
 * Z rotation
 * @param a
 * @param b
 * @param teta
 */
void	z_rotation(t_dot *a, t_dot *b, double teta)
{
	a->x = a->x * cos(teta) - a->y * sin(teta);
	a->y = (a->x) * sin(teta) + a->y * (cos(teta));
	b->x = b->x * cos(teta) - b->y * sin(teta);
	b->y = (b->x) * sin(teta) + b->y * (cos(teta));
}
