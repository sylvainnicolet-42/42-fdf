/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:10:53 by synicole          #+#    #+#             */
/*   Updated: 2023/03/15 23:10:55 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_hex_to_int(char *hex)
{
	int	i;
	int	len;
	int	val;
	int	decimal;

	len = (int) ft_strlen(hex);
	decimal = 0;
	i = 0;
	while (hex[i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 'A' + 10;
		decimal += val * pow(16, len);
		len--;
		i++;
	}
	return (decimal);
}
