#include "cub3d.h"

void	print_message_exit(char *message, int exit_code)
{
	ft_printf("%s\n", message);
	exit(exit_code);
}

void	print_exit_free(char *message, int exit_code, t_game *game)
{
	free_mem(game);
	print_message_exit(message, exit_code);
}