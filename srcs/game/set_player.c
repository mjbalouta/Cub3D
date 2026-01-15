#include "cub3d.h"

void	set_north_south(t_game *game, char orientation)
{
	if (orientation == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.planex = 0.66;
		game->player.planey = 0.0;
	}
	else if (orientation == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.planex = -0.66;
		game->player.planey = 0.0;
	}
}

void	set_weast_east(t_game *game, char orientation)
{
	if (orientation == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.planex = 0.0;
		game->player.planey = 0.66;
	}
	else if (orientation == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.planex = 0.0;
		game->player.planey = 0.66;
	}
}

void	set_player_direction(t_game *game, char orientation)
{
	if (orientation == 'N' || orientation == 'S')
		set_north_south(game, orientation);
	else if (orientation == 'E' || orientation == 'W')
		set_weast_east(game, orientation);
}

void	find_and_set_player(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map.map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				game->player.posx = (double)j + 0.5;
				game->player.posy = (double)i + 0.5;
				set_player_direction(game, map[i][j]);
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
