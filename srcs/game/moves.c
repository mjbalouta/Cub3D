/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:05 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:07 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	next_y = (int)(game->player.posy + (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posy += new_y;
	}
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx + (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posx += new_x;
	}
}

void	move_down(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	next_y = (int)(game->player.posy - (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posy -= new_y;
	}
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx - (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posx -= new_x;
	}
}

void	move_right(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	next_y = (int)(game->player.posy + (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posy += new_y;
	}
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx + (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posx += new_x;
	}
}

void	move_left(t_game *game, double new_y, double new_x)
{
	int	next_y;
	int	next_x;

	next_y = (int)(game->player.posy - (new_y * BOUNDARY));
	next_x = (int)(game->player.posx);
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posy -= new_y;
	}
	next_y = (int)(game->player.posy);
	next_x = (int)(game->player.posx - (new_x * BOUNDARY));
	if (next_x >= 0 && next_y >= 0
		&& next_y < game->map.height && game->map.map[next_y]
		&& next_x < (int)ft_strlen(game->map.map[next_y])
		&& game->map.map[next_y][next_x] != '1')
	{
		game->player.posx -= new_x;
	}
}
