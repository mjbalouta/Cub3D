/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:57 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:58 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Determines which texture to use based on wall side and ray direction
 * 
 * @param ray struct containing side and direction
 * @return int Texture's index: 0=NORTH, 1=SOUTH, 2=EAST, 3=WEST
 * 
 * Logic:
 * - side 0 = vertical wall (EW)
 * - side 1 = horizontal wall (NS)
 * - ray_dir = determine if we are looking to positive or negative
 */
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

/**
 * @brief Calculate the texture's coordenate x to be drawn
 * 
 * @param ray Ray's struct with colision's info
 * @param game Game's struct
 * @param wall wall's struct where you keep tex_x
 * 
 * Process:
 * 1. Calculate where the ray hit the wall (wall_x between 0 and 1)
 * 2. Convert to pixel coordenate in texture
 * 3. Flip texture if necessary (depending on directions)
 */
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
	if (ray->side == 0 && ray->ray_dir_x < 0)
		wall->tex_x = game->texture[tex_index].width - wall->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		wall->tex_x = game->texture[tex_index].width - wall->tex_x - 1;
}

/**
 * @brief Calculate wall's height on the screen and where to start/stop drawing
 * 
 * @param ray ray struct with perpendicular distance
 * @param game game struct with window height
 * @param wall struct where you store the calculated values
 * 
 * Process:
 * - line_height: wall's height in pixels (inversely proportional to distance)
 * - draw_start: Y pixel where to start drawing (top of wall)
 * - draw_end: Y pixel where to stop drawing (bottom of wall)
 * 
 * Limits applied to avoid drawubg outside the window
 */
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

/**
 * @brief Get the color of a specific pixel from the texture
 * 
 * @param texture pointer to texture struct
 * @param x X coordinate of pixel in texture
 * @param y Y coordinate of pixel in texture
 * @return int Color in RGBA format
 * 
 * Directly accesses the texture's imge buffer using:
 * - line_len: bytes per line
 * - bpp: bits per pixel
 */
int	get_texture_color(t_tex *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}
