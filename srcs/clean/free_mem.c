#include "cub3d.h"

void	free_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].img)
			mlx_destroy_image(game->mlx, game->texture[i].img);
		i++;
	}
}

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].path)
			free(game->texture[i].path);
		i++;
	}
}

void	free_window(t_game *game)
{
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->mlx_window)
	{
		mlx_clear_window(game->mlx, game->mlx_window);
		mlx_destroy_window(game->mlx, game->mlx_window);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_mem(t_game *game)
{
	int	i;

	free_textures(game);
	free_images(game);
	if (game->floor_color.code != NULL)
		free(game->floor_color.code);
	if (game->sky_color.code != NULL)
		free(game->sky_color.code);
	i = game->map.height - 1;
	while (i >= 0)
	{
		if (game->map.map[i])
			free(game->map.map[i]);
		i--;
	}
	if (game->map.map)
		free(game->map.map);
	free_window(game);
	get_next_line(-1);
}
