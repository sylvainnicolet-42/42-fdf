/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:19:19 by synicole          #+#    #+#             */
/*   Updated: 2023/02/02 00:19:21 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * @name ft_print_success
 * @def Print text in green and exit the program.
 *
 * @param char *str
 *
 * @return void
 */
void	ft_print_success(char *str)
{
	ft_printf("\033[0;32m");
	ft_printf("%s\n", str);
	exit(EXIT_SUCCESS);
}

/**
 * @name ft_print_error
 * @def Print text in red and exit the program.
 *
 * @param char *str
 *
 * @return void
 */
void	ft_print_error(char *str)
{
	ft_printf("\033[0;31m");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
