/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:39:54 by synicole          #+#    #+#             */
/*   Updated: 2023/02/01 20:39:56 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Libraries
*/
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

/**
 * @name s_data
 * @def
 *
 * @param t_mlx mlx
 * @param t_map map
 * @param int rgb
 * @param int win_height
 * @param int win_width
 */
typedef struct s_data
{
	int width
}	t_data;

void	ft_print_success(char *str);
void	ft_print_error(char *str);

#endif