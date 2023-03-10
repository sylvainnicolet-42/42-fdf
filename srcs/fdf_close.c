/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:31:11 by synicole          #+#    #+#             */
/*   Updated: 2023/03/10 20:31:12 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	fdf_close(t_param *params)
{
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	// TODO CLEAR params & matrix
	ft_print_success("FDF ended successfully! 🚀");
	return (0);
}