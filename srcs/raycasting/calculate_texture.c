#include "cub3d.h"

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
