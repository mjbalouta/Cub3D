/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:45 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:46 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief counts digits in a string
 * 
 * @param str 
 * @return int 
 */
int	count_digits_string(char *str)
{
	int	i;
	int	count_digits;

	i = 0;
	count_digits = 0;
	while (str[i])
	{
		if (ft_isdigit((int)(str[i])))
			count_digits++;
		i++;
	}
	return (count_digits);
}

/**
 * @brief counts digits in a number
 * 
 * @param num 
 * @return int 
 */
int	count_digits_numbers(int num)
{
	int	nr_digits;

	nr_digits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		nr_digits++;
	}
	return (nr_digits);
}
