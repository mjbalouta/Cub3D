#include "cub3d.h"

void	move_camera(t_game *game)
{

}

void	move_player(t_game *game)
{
	
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		handle_close(game);
	else if (keycode == 65361 || keycode == 65363)
		move_camera(game);
	else if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		move_player(game);
	else
		printf("%d\n", keycode);
	return (0);
}