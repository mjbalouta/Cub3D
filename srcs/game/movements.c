#include "cub3d.h"

void	rotate(t_game *game, double angle)
{
    double  old_dirx;
    double  old_planex;

    old_dirx = game->player.dir_x;
    old_planex = game->player.planex;
    game->player.dir_x = old_dirx * cos(angle) - game->player.dir_y * sin(angle);
    game->player.dir_y = old_dirx * sin(angle) + game->player.dir_y * cos(angle);
    game->player.planex = old_planex * cos(angle) - game->player.planey * sin(angle);
    game->player.planey = old_planex * sin(angle) + game->player.planey * cos(angle);
}

void	move_up(t_game *game, double new_y, double new_x)
{
    int	next_y;
    int	next_x;
    
    // Check Y movement
    next_y = (int)(game->player.posy + (new_y * BOUNDARY));
    next_x = (int)(game->player.posx);
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posy += new_y;
    }
    
    // Check X movement
    next_y = (int)(game->player.posy);
    next_x = (int)(game->player.posx + (new_x * BOUNDARY));
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posx += new_x;
    }
}

void	move_down(t_game *game, double new_y, double new_x)
{
    int	next_y;
    int	next_x;
    
    // Check Y movement
    next_y = (int)(game->player.posy - (new_y * BOUNDARY));
    next_x = (int)(game->player.posx);
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posy -= new_y;
    }
    
    // Check X movement
    next_y = (int)(game->player.posy);
    next_x = (int)(game->player.posx - (new_x * BOUNDARY));
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posx -= new_x;
    }
}

void	move_right(t_game *game, double new_y, double new_x)
{
    int	next_y;
    int	next_x;
    
    // Check Y movement
    next_y = (int)(game->player.posy + (new_y * BOUNDARY));
    next_x = (int)(game->player.posx);
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posy += new_y;
    }
    
    // Check X movement
    next_y = (int)(game->player.posy);
    next_x = (int)(game->player.posx + (new_x * BOUNDARY));
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posx += new_x;
    }
}

void	move_left(t_game *game, double new_y, double new_x)
{
    int	next_y;
    int	next_x;
    
    // Check Y movement
    next_y = (int)(game->player.posy - (new_y * BOUNDARY));
    next_x = (int)(game->player.posx);
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posy -= new_y;
    }
    
    // Check X movement
    next_y = (int)(game->player.posy);
    next_x = (int)(game->player.posx - (new_x * BOUNDARY));
    
    if (next_x >= 0 && next_y >= 0 && 
        next_y < game->map.height && game->map.map[next_y] &&
        next_x < (int)ft_strlen(game->map.map[next_y]) &&
        game->map.map[next_y][next_x] != '1' &&
        game->map.map[next_y][next_x] != ' ')
    {
        game->player.posx -= new_x;
    }
}

void	move_player(t_game *game)
{
    if (game->player.move_up == 1)
        move_up(game, game->player.dir_y * SPEED, game->player.dir_x * SPEED);
    if (game->player.move_down == 1)
        move_down(game, game->player.dir_y * SPEED, game->player.dir_x * SPEED);
    if (game->player.move_right == 1)
        move_right(game, game->player.planey * SPEED, game->player.planex * SPEED);
    if (game->player.move_left == 1)
        move_left(game, game->player.planey * SPEED, game->player.planex * SPEED);
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