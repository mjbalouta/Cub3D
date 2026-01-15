#include "cub3d.h"

void	draw_column(t_game *game, int x, t_ray *ray)
{
	t_wall	wall;

	calculate_wall_height(ray, game, &wall);
	calculate_texture_x(ray, game, &wall);
	draw_ceiling_floor(game, x, &wall);
	draw_wall_column(game, x, ray, &wall);
}

void	cast_ray(t_game *game, int x, t_ray *ray)
{
	calculate_ray_direction(game, x, ray);
	calculate_step_and_side_dist(game, ray);
	perform_dda(game, ray);
	calculate_wall_distance(ray);
}

void	finalize_colors(t_game *game)
{
	game->floor_color.color = (game->floor_color.rgb[0] << 16)
		| (game->floor_color.rgb[1] << 8)
		| game->floor_color.rgb[2];
	game->sky_color.color = (game->sky_color.rgb[0] << 16)
		| (game->sky_color.rgb[1] << 8)
		| game->sky_color.rgb[2];
}

void	start_ray(t_game *game)
{
	int	x;

	finalize_colors(game);
	x = 0;
	while (x < game->win_width)
	{
		cast_ray(game, x, &game->ray);
		draw_column(game, x, &game->ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->screen.img, 0, 0);
}
