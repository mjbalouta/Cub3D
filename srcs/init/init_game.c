#include "cub3d.h"

void	init_img(t_game *game)
{
	game->screen.img = mlx_new_image(
		game->mlx,
		game->win_width,
		game->win_height
	);
	if (!game->screen.img)
		print_exit_free("Failed to create screen image", 1, game);
	game->screen.addr = mlx_get_data_addr(
		game->screen.img,
		&game->screen.bpp,
		&game->screen.line_len,
		&game->screen.endian
	);
	if (!game->screen.addr)
		print_exit_free("Failed to get screen image addr", 1, game);
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
	game->win_width = 1024;
	game->win_height = 768;
	game->map.width = 0;
	game->map.height = 0;
	game->map.map = NULL;
	init_texture_struct(game);
	init_color_struct(game);
	init_mlx(game);
	init_img(game);
}
