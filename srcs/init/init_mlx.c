#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win_height = 800;
	game->win_width = 1000;
	game->mlx_window = mlx_new_window(game->mlx,
		game->win_width, game->win_height, "Lego Cub3D");
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
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
