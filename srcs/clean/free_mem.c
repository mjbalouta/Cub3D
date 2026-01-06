#include "cub3d.h"

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
}