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

void	free_mem(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].path)
			free(game->texture[i].path);
		i++;
	}
	if (game->floor_color.code)
		free(game->floor_color.code);
	if (game->sky_color.code)
		free(game->sky_color.code);
	i = game->map.height - 1;
	while (i >= 0)
	{
		if (game->map.map[i])
			free(game->map.map[i]);
		i--;
	}
	if (game->map.map)
		free(game->map.map);
	get_next_line(-1);
}
