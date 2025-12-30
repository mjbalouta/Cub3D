#include "cub3d.h"

int main(int ac, char **av)
{
	t_game	*game;
	if (ac != 2 || validate_file_name(av[1]) != 0)
		return (ft_printf("The program must be run with a something.cub file.\n"));
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Malloc game failed\n"));
	init_game(&game);
	return (0);
}