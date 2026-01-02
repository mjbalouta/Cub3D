#include "cub3d.h"
	
void	create_linked_list(t_game *game, t_map_file **map_list, int fd)
{
	t_map_file	*head;
	char		*line;
	t_map_file	*current;

	head = NULL;
	current = NULL;
	line = get_next_line(fd);
	if(!line)
		print_exit_free("Error\nNonexisting map.", 1, game);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (!head)
		{
			head = malloc(sizeof(t_map_file)); //this means that head will always point to the first node (just by allocating mem)
			current = head;
		}
		else
		{
			current->next = malloc(sizeof(t_map_file)); //allocates mem for a new node
			current = current->next;
		}
		current->line = line;
		current->next = NULL;
		line = get_next_line(fd);
	}
	*map_list = head;
}

void	create_map_copy(t_map_file **map_list, t_game *game, int size)
{
	t_map_file	*temp;
	int			i;

	temp = *map_list;
	i = 0;
	game->map.map = ft_calloc(size + 1, sizeof(char **));
	if (!game->map.map)
	{
		free_list(map_list);
		print_exit_free("Error\nError allocating memory for the map.", 1, game);
	}
	while (temp)
	{
		game->map.map[i++] = ft_strdup(temp->line);
		if (!game->map.map)
		{
			free_list(map_list);
			print_exit_free("Error\nError allocating memory for the map.", 1, game);
		}
		if ((int)ft_strlen(temp->line) > game->map.width)
			game->map.width = ft_strlen(temp->line);
		game->map.height++;
		temp = temp->next;
	}
}
