#include "cub3d.h"

void	draw_column(t_game *game, int x, t_ray *ray)
{
	t_wall	wall;

	calculate_wall_height(ray, game, &wall);
	calculate_texture_x(ray, game, &wall);
	draw_ceiling_floor(game, x, &wall);
	draw_wall_column(game, x, ray, &wall);
}

/**
 * @brief Here we will initialize all the necessary variables for the raycasting
 * 
 * @param game our struct
 * @param x which position of the x position in our map we are
 * @param ray our ray struct
 */
void	calculate_ray_direction(t_game *game, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)game->win_width - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.planex * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.planey * ray->camera_x;
	ray->map_x = (int)game->player.posx;
	ray->map_y = (int)game->player.posy;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
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
