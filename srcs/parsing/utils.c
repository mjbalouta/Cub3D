/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:42 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:43 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief frees double char** arrays
 * 
 * @param strs 
 */
void	free_arrays(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

/**
 * @brief counts the strings in a double char**
 * 
 * @param strs 
 * @return int 
 */
int	count_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

/**
 * @brief counts the size of the map's linked list
 * 
 * @param map_list 
 * @return int 
 */
int	list_size(t_map_file *map_list)
{
	int			size;
	t_map_file	*temp;

	size = 0;
	temp = map_list;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/**
 * @brief detects whitespaces
 * 
 * @param a 
 * @return int 
 */
int	is_whitespace(char a)
{
	if ((a >= 9 && a <= 13) || a == ' ')
		return (1);
	return (0);
}
