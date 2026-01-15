#include "cub3d.h"

void	free_list(t_map_file **map_list)
{
	t_map_file	*next;
	t_map_file	*current;

	if (!map_list || !*map_list)
		return ;
	current = *map_list;
	while (current)
	{
		next = current->next;
		if (current->line)
			free(current->line);
		free(current);
		current = next;
	}
	*map_list = NULL;
}