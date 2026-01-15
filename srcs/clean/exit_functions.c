#include "cub3d.h"

/**
 * @brief prints a message and exits
 * 
 * @param message 
 * @param exit_code 
 */
void	print_message_exit(char *message, int exit_code)
{
	ft_printf("Error\n%s\n", message);
	exit(exit_code);
}

/**
 * @brief frees memory and calls print_message_exit()
 * 
 * @param message 
 * @param exit_code 
 * @param game 
 */
void	print_exit_free(char *message, int exit_code, t_game *game)
{
	free_mem(game);
	print_message_exit(message, exit_code);
}

int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}
