#include "cub3d.h"

void	move_up(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	// Check Y movement
	next_y = (int)(game->player.posy + (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posy += new_y;
	}
	// Check X movement
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx + (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posx += new_x;
	}
}

void	move_down(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	// Check Y movement
	next_y = (int)(game->player.posy - (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posy -= new_y;
	}
	// Check X movement
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx - (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posx -= new_x;
	}
}

void	move_right(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	// Check Y movement
	next_y = (int)(game->player.posy + (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posy += new_y;
	}
	// Check X movement
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx + (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posx += new_x;
	}
}

void	move_left(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	// Check Y movement
	next_y = (int)(game->player.posy - (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posy -= new_y;
	}
	// Check X movement
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx - (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1'
		&& game->map.map[next_y][next_x] != ' ')
	{
		game->player.posx -= new_x;
	}
}
