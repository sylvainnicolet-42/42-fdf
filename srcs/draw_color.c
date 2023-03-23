/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:46:14 by synicole          #+#    #+#             */
/*   Updated: 2023/03/22 18:46:17 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Get color of points with z value
 * @param params
 */
static int	get_color_from_params(t_param *params)
{
	if (params->color == P_BLACK)
		return (BLACK);
	else if (params->color == P_WHITE)
		return (WHITE);
	else if (params->color == P_RED)
		return (RED);
	else if (params->color == P_GREEN)
		return (GREEN);
	else if (params->color == P_BLUE)
		return (BLUE);
	else if (params->color == P_YELLOW)
		return (YELLOW);
	else if (params->color == P_PINK)
		return (PINK);
	else if (params->color == P_CYAN)
		return (CYAN);
	else if (params->color == P_ORANGE)
		return (ORANGE);
	else
		return (P_COLOR);
}

/**
 * Set the color of the line
 * @param a t_dot
 * @param b t_dot
 * @return int color
 */
int	get_color(t_dot a, t_dot b, t_param *params)
{
	(void) params;
	if (a.color)
		return (a.color);
	else if (b.color)
		return (b.color);
	if (a.has_height == 1 || b.has_height == 1)
		return (get_color_from_params(params));
	return (P_COLOR_GRID);
}
