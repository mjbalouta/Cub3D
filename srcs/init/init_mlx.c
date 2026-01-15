#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, "Lego Cub3D");
}

int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		handle_close(game);
	else
		printf("%d\n", keycode);
	return (0);
}
