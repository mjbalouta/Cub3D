/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:08 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:09 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_game *game, double angle)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->player.dir_x;
	old_planex = game->player.planex;
	game->player.dir_x = old_dirx
		* cos(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = old_dirx
		* sin(angle) + game->player.dir_y * cos(angle);
	game->player.planex = old_planex
		* cos(angle) - game->player.planey * sin(angle);
	game->player.planey = old_planex
		* sin(angle) + game->player.planey * cos(angle);
}
