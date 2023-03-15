/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:38:14 by synicole          #+#    #+#             */
/*   Updated: 2023/02/01 20:38:16 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Main function for the FDF application
 * @param argc Number of arguments passed to the application
 * @param argv Array of arguments passed to the application
 * @return Integer value indicating the success or failure of the application
 */
int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_param	*params;

	if (argc == 2)
	{
		matrix = read_map(argv[1]);
		params = params_build(matrix);
		draw(params);
		handle_event(params);
		mlx_loop(params->mlx_ptr);
	}
	else
		ft_print_error("Usage : ./fdf [file]");
	return (0);
}
