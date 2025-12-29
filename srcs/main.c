#include "cub3d.h"

void	print_parsing(t_game *game)
{
	int i = 0;

	ft_printf("TEXTURES:\n");
	while (i < 4)
	{
		ft_printf("%d  %s\n", game->texture[i].defined, game->texture[i].path);
		i++;
	}
	ft_printf("COLORING:\n");
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
}

int main(int ac, char **av)
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));
	if (validate_args(ac, av) != 0 || validate_file(av[1], &game) != 0)
		return (1);
	print_parsing(&game);
	return (0);
}