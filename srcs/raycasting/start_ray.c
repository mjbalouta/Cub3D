#include "cub3d.h"

/**
 * @brief Draws a complete column (sky + wall + floor)
 * 
 * @param game struct
 * @param x column X to be drawn
 * @param ray information for this column
 * 
 * Drawing order:
 * 1. Calculate wall height
 * 2. Calculate texture X coordinate
 * 3. Draw sky and floor
 * 4. Draw textured wall
 */
void	draw_column(t_game *game, int x, t_ray *ray)
{
	t_wall	wall;

	calculate_wall_height(ray, game, &wall);
	calculate_texture_x(ray, game, &wall);
	draw_ceiling_floor(game, x, &wall);
	draw_wall_column(game, x, ray, &wall);
}

/**
 * @brief Initializes necessary variables for raycasting a column
 * 
 * @param game our struct
 * @param x current column X (0 to win_width-1)
 * @param ray our ray struct to be initialized
 * 
 * Calculations:
 * - camera_x: position on camera (-1 = left, 0 = center, +1 = right)
 * - ray_dir: ray direction in 2D world
 * - map x/y: grid cell where player is
 * - delta_dist: distance ray travels to cross 1 cell
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

/**
 * @brief Executes entire raycasting process for one column
 * 
 * @param game struct
 * @param x Column X to be processed
 * @param ray struct
 * 
 * Complete process:
 * 1. Calculate ray direction
 * 2. Calculate step and side_dist
 * 3. Execute DDA until hitting wall
 * 4. Calculate distance to wall
 */
void	cast_ray(t_game *game, int x, t_ray *ray)
{
	calculate_ray_direction(game, x, ray);
	calculate_step_and_side_dist(game, ray);
	perform_dda(game, ray);
	calculate_wall_distance(ray);
}

/**
 * @brief Converts RGB values to integer format for MLX
 * 
 * @param game struct with color in RGB
 * 
 * Format: 0x00RRGGBB
 * - R shifted 16 bits left
 * - G shifted 8 bits left
 * - B not shifted
 */
void	finalize_colors(t_game *game)
{
	game->floor_color.color = (game->floor_color.rgb[0] << 16)
		| (game->floor_color.rgb[1] << 8)
		| game->floor_color.rgb[2];
	game->sky_color.color = (game->sky_color.rgb[0] << 16)
		| (game->sky_color.rgb[1] << 8)
		| game->sky_color.rgb[2];
}

/**
 * @brief Main raycasting function (where it all begins) - renders complete frame
 * 
 * @param game struct
 * 
 * Process:
 * 1. Finalize colors (convert RGB to int)
 * 2. For each screen column X (0 to win_width-1):
 * 	- cast a ray
 * 	- draw the column (sky + wall + floor)
 * 3. 3D rendered frame with textures
 * 
 * Result: 3D rendered frame with textures
 */
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
