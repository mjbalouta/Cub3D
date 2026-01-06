#include "../includes/cub3d.h"
#include "stdio.h"

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(
			game->mlx,
			game->texture[i].path,
			&game->texture[i].height,
			&game->texture[i].width
		);
		if (!game->texture[i].img)
			print_exit_free("Failed to load texture", 1, game);
		game->texture[i].addr = mlx_get_data_addr(
			game->texture[i].img,
			&game->texture[i].bpp,
			&game->texture[i].line_len,
			&game->texture[i].endian
		);
		if (!game->texture[i].addr)
			print_exit_free("Failed to load texture", 1, game);
		i++;
	}
}
