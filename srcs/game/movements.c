#include "cub3d.h"

// void	move_camera(t_game *game)
// {

// }

void	move_up(t_game *game, double new_y, double new_x)
{
	if (game->player.posy + new_y != '1' && game->player.posx + new_x != '1')
	{
		game->player.posx = new_x;
		game->player.posy = new_y;
	}
}

void	move_player(t_game *game)
{
	printf("player x: %f\n", game->player.posx);
	printf("player y: %f\n", game->player.posy);
	if (game->player.move_up == 1)
		move_up(game, game->player.posy * SPEED, game->player.posx * SPEED);
	printf("player x: %f\n", game->player.posx);
	printf("player y: %f\n", game->player.posy);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		handle_close(game);
	// else if (keycode == XK_a)
	// 	game->player.move_left = 1;
	// else if (keycode == XK_d)
	// 	game->player.move_right = 1;
	else if (keycode == XK_w)
	{
		game->player.move_up = 1;
		move_player(game);
	}
	// else if (keycode == XK_s)
	// 	game->player.move_down = 1;
	// else if (keycode == XK_Left)
	// 	game->player.rotate_left = 1;
	// else if (keycode == XK_Right)
	// 	game->player.rotate_right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		handle_close(game);
	// else if (keycode == XK_a)
	// 	game->player.move_left = 0;
	// else if (keycode == XK_d)
	// 	game->player.move_right = 0;
	else if (keycode == XK_w)
		game->player.move_up = 0;
	// else if (keycode == XK_s)
	// 	game->player.move_down = 0;
	// else if (keycode == XK_Left)
	// 	game->player.rotate_left = 0;
	// else if (keycode == XK_Right)
	// 	game->player.rotate_right = 0;
	return (0);
}