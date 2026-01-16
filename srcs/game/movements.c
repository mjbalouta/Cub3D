#include "cub3d.h"

void	move_player(t_game *game)
{
	if (game->player.move_up == 1)
		move_up(game, game->player.dir_y * SPEED, game->player.dir_x * SPEED);
	if (game->player.move_down == 1)
		move_down(game, game->player.dir_y * SPEED, game->player.dir_x * SPEED);
	if (game->player.move_right == 1)
		move_right(game, game->player.planey
			* SPEED, game->player.planex * SPEED);
	if (game->player.move_left == 1)
		move_left(game, game->player.planey
			* SPEED, game->player.planex * SPEED);
	if (game->player.rotate_right == 1)
		rotate(game, ROTATE_SPEED);
	if (game->player.rotate_left == 1)
		rotate(game, -ROTATE_SPEED);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		handle_close(game);
	else if (keycode == XK_a)
		game->player.move_left = 1;
	else if (keycode == XK_d)
		game->player.move_right = 1;
	else if (keycode == XK_w)
		game->player.move_up = 1;
	else if (keycode == XK_s)
		game->player.move_down = 1;
	else if (keycode == XK_Left)
		game->player.rotate_left = 1;
	else if (keycode == XK_Right)
		game->player.rotate_right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		handle_close(game);
	else if (keycode == XK_a)
		game->player.move_left = 0;
	else if (keycode == XK_d)
		game->player.move_right = 0;
	else if (keycode == XK_w)
		game->player.move_up = 0;
	else if (keycode == XK_s)
		game->player.move_down = 0;
	else if (keycode == XK_Left)
		game->player.rotate_left = 0;
	else if (keycode == XK_Right)
		game->player.rotate_right = 0;
	return (0);
}
