#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, "Lego Cub3D");
}
