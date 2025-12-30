/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:57:10 by brmaria-          #+#    #+#             */
/*   Updated: 2025/12/30 18:53:36 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_color_struct(t_game *game)
{
	int	i;

	i = 0;
	game->floor_color.defined = 0;
	game->sky_color.defined = 0;
	game->floor_color.code = NULL;
	game->sky_color.code = NULL;
	while (i < 3)
	{
		game->floor_color.rgb[i] = -1;
		game->sky_color.rgb[i] = -1;
		i++;
	}
}

void	init_texture_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = NULL;
		game->texture[i].path = NULL;
		game->texture[i].width = 0;
		game->texture[i].height = 0;
		game->texture[i].defined = 0;
		i++;
	}
}

/**
 * @brief initializing game's struct
 * 
 * @param game struct to be initialized
 */
void	init_game(t_game *game)
{
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
	init_texture_struct(game);
}
