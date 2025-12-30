/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:57:10 by brmaria-          #+#    #+#             */
/*   Updated: 2025/12/30 16:50:16 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief initializing game's struct
 * 
 * @param game struct to be initialized
 */
void	init_game(t_game *game)
{
	int	i;

	i = 0;
	ft_bzero(game, sizeof(t_game));
	game->win_width = 1024;
	game->win_height = 768;
	game->player.x = 1.5;
	game->player.y = 1.5;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->map.width = 0;
	game->map.height = 0;
	game->map.map = NULL;
	while (i < 4)
	{
		game->texture[i].img = NULL;
		game->texture[i].path = NULL;
		game->texture[i].width = 0;
		game->texture[i].height = 0;
		i++;
	}
}
