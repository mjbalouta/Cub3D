/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:18 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:19 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_game *game)
{
	move_player(game);
	start_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->screen.img, 0, 0);
	return (0);
}

void	init_img(t_game *game)
{
	game->screen.img = mlx_new_image(
			game->mlx,
			game->win_width,
			game->win_height
			);
	if (!game->screen.img)
		print_exit_free(CREATE_SCREEN_ERROR, 1, game);
	game->screen.addr = mlx_get_data_addr(
			game->screen.img,
			&game->screen.bpp,
			&game->screen.line_len,
			&game->screen.endian
			);
	if (!game->screen.addr)
		print_exit_free(GET_SCREEN_ERROR, 1, game);
}

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
	game->win_width = 1920;
	game->win_height = 1080;
	game->map.width = 0;
	game->map.height = 0;
	game->map.map = NULL;
	init_texture_struct(game);
	init_color_struct(game);
}
