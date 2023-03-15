/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:29:05 by synicole          #+#    #+#             */
/*   Updated: 2023/03/12 13:29:07 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Handle events on the window
 * @param params
 */
void	handle_event(t_param *params)
{
	mlx_hook(params->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_hook, params);
	mlx_mouse_hook(params->win_ptr, mouse_hook, params);
	mlx_hook(params->win_ptr, ON_DESTROY, KEY_PRESS_MASK, fdf_close, params);
}
