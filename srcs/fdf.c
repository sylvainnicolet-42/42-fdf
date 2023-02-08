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

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc == 2)
	{
		matrix = read_map(*++argv);
		set_default(&PRM);
		draw(matrix);
		mlx_key_hook(PRM.win_ptr, deal_key, matrix);
		mlx_loop(PRM.mlx_ptr);
	}
	else
		ft_print_error("Usage : ./fdf [file]");
}
