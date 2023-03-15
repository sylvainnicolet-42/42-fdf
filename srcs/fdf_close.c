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

/**
 * Clear the matrix
 * @param matrix
 * @return int
 */
static void	matrix_clear(t_dot **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/**
 * Close properly FDD
 * @param params
 * @return int
 */
int	fdf_close(t_param *params)
{
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	matrix_clear(params->matrix);
	free(params);
	ft_print_success("FDF ended successfully! 🚀");
	return (0);
}
