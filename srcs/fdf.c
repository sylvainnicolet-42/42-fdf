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
 * Function to build the parameters structure.
 * @param matrix The matrix of points.
 * @return Pointer to the parameters structure.
 */
t_param	*params_build(t_dot **matrix)
{
	t_param *param;
	void	*mlx_ptr;
	void	*win_ptr;

	param = malloc(sizeof(t_param));
	if (!param)
		ft_print_error("Malloc error");
	param->matrix = matrix;
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 800;
	param->win_y = 800;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		ft_print_error("mlx_init error");
	param->mlx_ptr = mlx_ptr;
	win_ptr = mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
	if (!win_ptr)
		ft_print_error("mlx_new_window error");
	param->win_ptr = win_ptr;
	return (param);
}

/**
 * Main function for the FDF application.
 * @param argc Number of arguments passed to the application.
 * @param argv Array of arguments passed to the application.
 * @return Integer value indicating the success or failure of the application.
 */
int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_param *params;

	if (argc == 2)
	{
		matrix = read_map(argv[1]);
		params = params_build(matrix);
		draw(matrix, params);
		mlx_key_hook(params->win_ptr, deal_key, params);
		mlx_mouse_hook(params->win_ptr, mouse_hook, params);
		mlx_hook(params->win_ptr, ON_DESTROY, KEY_PRESS_MASK, fdf_close, params);
		mlx_loop(params->mlx_ptr);
	}
	else
		ft_print_error("Usage : ./fdf [file]");
	return (0);
}
