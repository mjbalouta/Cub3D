#include "cub3d.h"

int main(int ac, char **av)
{
	if (ac != 2 || validate_file_name(av[1]) != 0)
		return (ft_printf("The program must be run with a something.cub file.\n"));
}