#include "cub3d.h"

int main(int ac, char **av)
{
	t_game *game;

	if (validate_args(ac, av) != 0 || validate_file(av[1], &game) != 0)
		return (1);
	return (0);
}