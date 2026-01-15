#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall_column(t_game *game, int x, t_ray *ray, t_wall *wall)
{
	int		y;
	int		tex_index;
	int		tex_y;
	int		color;
	double	step;

	tex_index = get_texture_index(ray);
	step = 1.0 * game->texture[tex_index].height / wall->line_height;
	game->tex_pos = (wall->draw_start - game->win_height
			/ 2 + wall->line_height / 2) * step;
	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)game->tex_pos & (game->texture[tex_index].height - 1);
		game->tex_pos += step;
		color = get_texture_color(&game->texture[tex_index],
				wall->tex_x, tex_y);
		my_mlx_pixel_put(&game->screen, x, y, color);
		y++;
	}
}

void	draw_ceiling_floor(t_game *game, int x, t_wall *wall)
{
	int	y;

	y = 0;
	while (y < wall->draw_start)
	{
		my_mlx_pixel_put(&game->screen, x, y, game->sky_color.color);
		y++;
	}
	y = wall->draw_end;
	while (y < game->win_height)
	{
		my_mlx_pixel_put(&game->screen, x, y, game->floor_color.color);
		y++;
	}
}
