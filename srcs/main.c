/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:09:09 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:09:10 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	validate_args(ac, av, &game);
	validate_file(av[1], &game);
	init_mlx(&game);
	init_img(&game);
	load_textures(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.mlx_window, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.mlx_window, KeyRelease, KeyRelease, handle_keyrelease, &game);
	mlx_hook(game.mlx_window, 17, 0, &handle_close, &game);
	mlx_loop(game.mlx);
	free_mem(&game);
	return (0);
}
