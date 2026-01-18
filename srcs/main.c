#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	validate_args(ac, av, &game);
	validate_file(av[1], &game);
	init_mlx(&game);
	init_img(&game);
	load_textures(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.mlx_window, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.mlx_window, KeyRelease, KeyRelease, handle_keyrelease, &game);
	mlx_hook(game.mlx_window, 17, 0, &handle_close, &game);
	mlx_loop(game.mlx);
	free_mem(&game);
	return (0);
}
