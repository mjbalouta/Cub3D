#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (2);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (3);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (0);
	return (1);
}

void	calculate_texture_x(t_ray *ray, t_game *game, t_wall *wall)
{
	double	wall_x;
	int		tex_index;

	tex_index = get_texture_index(ray);
	if (ray->side == 0)
		wall_x = game->player.posy + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.posx + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	wall->tex_x = (int)(wall_x * (double)game->texture[tex_index].width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		wall->tex_x = game->texture[tex_index].width - wall->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		wall->tex_x = game->texture[tex_index].width - wall->tex_x - 1;
}

void	calculate_wall_height(t_ray *ray, t_game *game, t_wall *wall)
{
	wall->line_height = (int)(game->win_height / ray->perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + game->win_height / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + game->win_height / 2;
	if (wall->draw_end >= game->win_height)
		wall->draw_end = game->win_height - 1;
}

int	get_texture_color(t_tex *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_wall_column(t_game *game, int x, t_ray *ray, t_wall *wall)
{
	int		y;
	int		tex_index;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	tex_index = get_texture_index(ray);
	step = 1.0 * game->texture[tex_index].height / wall->line_height;
	tex_pos = (wall->draw_start - game->win_height / 2 + wall->line_height / 2) * step;
	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)tex_pos & (game->texture[tex_index].height - 1);
		tex_pos += step;
		color = get_texture_color(&game->texture[tex_index], wall->tex_x, tex_y);
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
	ray->delta_dist_x = fabs(1/ ray->ray_dir_x);
	ray->delta_dist_y = fabs(1/ ray->ray_dir_y);
}

/**
 * @brief Decides what's the ray's direction
 * 
 * @param game 
 * @param ray 
 */
void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.posx - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.posx) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.posy - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.posy) * ray->delta_dist_y;
	}
}
/**
 * @brief 
 * 
 * @param game 
 * @param ray 
 */
void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; 
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; 
		}
		if (ray->map_x < 0 || ray->map_x >= game->map.width || ray->map_y < 0 || ray->map_y >= game->map.height)
			continue ;
		else if (game->map.map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	calculate_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
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
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->screen.img, 0, 0);
}