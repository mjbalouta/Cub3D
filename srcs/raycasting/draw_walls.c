#include "cub3d.h"

/**
 * @brief Puts a colored pixel on the screen image
 * 
 * @param img Image struct where to draw
 * @param x X coordinate on screen
 * @param y Y coordinate on screen
 * @param color Color to be drawn
 * 
 * Checks bounds and writes directly to image buffer
 */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Draws a vertical column of textured wall
 * 
 * @param game struct
 * @param x Screen column X to be drawn
 * @param ray Ray information
 * @param wall Wall information (height, start, end)
 * 
 * Process:
 * 1. Calculate "step" - how much to advance in texture per screen pixel
 * 2. For each Y pixel between draw_start and draw_end:
 *  - Determine which Y line of texture to use
 * 	- Get color of that texture pixel
 * 	- Draw on screen
 */
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

/**
 * @brief Draw's ceiling (sky) and floor for a vertical column
 * 
 * @param game struct with sky and floor colors
 * @param x Screen column X
 * @param wall Wall information (where it starts and ends)
 * 
 * Draws:
 * - Sky: from top (y=0) to draw_start
 * - Floor: from draw_end to bottom of window
 */
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
