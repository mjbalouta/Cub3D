/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:28 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:29 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief reads the map from the file and creates a linked list
 * containing each line of the map
 * 
 * @param game 
 * @param map_list 
 * @param fd 
 */
void	create_linked_list(t_game *game, t_map_file **map_list, int fd)
{
	t_map_file	*head;
	char		*line;
	t_map_file	*current;

	head = NULL;
	line = get_next_line(fd);
	if (!line)
		print_exit_free(NO_MAP_ERROR, 1, game);
	while (line != NULL)
	{
		if (!head)
		{
			head = malloc(sizeof(t_map_file));
			current = head;
		}
		else
		{
			current->next = malloc(sizeof(t_map_file));
			current = current->next;
		}
		current->line = line;
		current->next = NULL;
		line = get_next_line(fd);
	}
	*map_list = head;
}

/**
 * @brief allocates mem to store the map in the char ** game->map.map
 * 
 * @param game 
 * @param size 
 * @param map_list 
 */
void	allocate_map_mem(t_game *game, int size, t_map_file **map_list)
{
	game->map.map = ft_calloc(size + 1, sizeof(char **));
	if (!game->map.map)
	{
		free_list(map_list);
		print_exit_free(MAP_MEM_ERROR, 1, game);
	}
}

/**
 * @brief skips newlines that exist before the map
 * and if there are no lines with content after the newlines
 * it returns the error nonexisting map
 * 
 * @param temp 
 * @param map_list 
 * @param size 
 * @param game 
 * @return int 
 */
int	skip_newline(t_map_file **temp, t_map_file **map, int size, t_game *game)
{
	while (ft_strncmp((*temp)->line, "\n", 1) == 0)
	{
		if ((*temp)->next)
			(*temp) = (*temp)->next;
		else
		{
			free_list(map);
			print_exit_free(NO_MAP_ERROR, 1, game);
		}
		size--;
	}
	return (size);
}

/**
 * @brief creates a copy of the map's linked list to a char**
 * 
 * @param map_list 
 * @param game 
 * @param size 
 */
void	create_map_copy(t_map_file **map_list, t_game *game, int size)
{
	t_map_file	*temp;
	int			i;

	temp = *map_list;
	i = 0;
	skip_newline(&temp, map_list, size, game);
	allocate_map_mem(game, size, map_list);
	while (temp)
	{
		game->map.map[i] = ft_strdup(temp->line);
		if (!game->map.map[i++])
		{
			free_list(map_list);
			print_exit_free(MAP_MEM_ERROR, 1, game);
		}
		if ((int)ft_strlen(temp->line) > game->map.width)
			game->map.width = ft_strlen(temp->line);
		game->map.height++;
		temp = temp->next;
	}
}
