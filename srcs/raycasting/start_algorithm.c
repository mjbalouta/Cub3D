/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:09:03 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:09:04 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Determines the direction of ray movement in the grid
 * 
 * @param game struct with player position
 * @param ray struct to store step and side_dist
 * 
 * For each axis (X and Y):
 * - Determine if ray goes positive (+1) or negative (-1)
 * - Calculate distance to next grid line
 * 
 * side_dist: distance from player to next gridline
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
		ray->side_dist_x = (ray->map_x + 1.0
				- game->player.posx) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.posy - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0
				- game->player.posy) * ray->delta_dist_y;
	}
}

/**
 * @brief DDA (Digital Differential Analyzer) algorithm for raycasting
 * 
 * @param game struct with the map
 * @param ray struct being traced
 * 
 * Process:
 * 1. Advance ray cell by cell in the grid
 * 2. Always move in nearest direction (smallest side_dist)
 * 3. Stop when finding a wall ('1') or going out of bounds
 * 
 * side: indicates if hit vertical wall (0) or horizontal wall (1)
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
		if (ray->map_x < 0 || ray->map_x >= game->map.width
			|| ray->map_y < 0 || ray->map_y >= game->map.height)
			continue ;
		else if (game->map.map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/**
 * @brief Calculates perpendicular distance from player to wall
 * 
 * @param ray struct
 * 
 * Uses perpendicular distance (not euclidean) to avoid "fish-eye" effect
 * Perpendicular distance is distance projected in player's looking direction
 * 
 * Subtract delta_dist because side_dist already advanced one extra cell
 */
void	calculate_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
