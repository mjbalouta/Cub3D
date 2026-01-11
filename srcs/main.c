#include "../includes/cub3d.h"

void	print_parsing(t_game *game)
{
	int i = 0;

	ft_printf("\nTEXTURES:\n");
	while (i < 4)
	{
		ft_printf("%d  %s\n", game->texture[i].defined, game->texture[i].path);
		i++;
	}
	ft_printf("\nCOLORING:\n");
	i = 0;
	ft_printf("F %d ", game->floor_color.defined);
	while (i < 3)
	{
		ft_printf("%d", game->floor_color.rgb[i]);
		if (i != 2)
			ft_printf(",");
		i++;
	}
	i = 0;
	ft_printf("\nS %d ", game->sky_color.defined);
	while (i < 3)
	{
		ft_printf("%d", game->sky_color.rgb[i]);
		if (i != 2)
			ft_printf(",");
		i++;
	}
	ft_printf("\n");
	ft_printf("\nMAP:\n");
	i = 0;
	while (i < game->map.height)
	{
		ft_printf("%s", game->map.map[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	validate_args(ac, av, &game);
	validate_file(av[1], &game);
	//print_parsing(&game);
	load_textures(&game);
	start_ray(&game);
	mlx_key_hook(game.mlx_window, handle_keypress, &game);
	mlx_hook(game.mlx_window, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	free_mem(&game);
	return (0);
}
