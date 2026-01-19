/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:09:52 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:11:56 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player
{
	char	orientation; //direction the player's facing from map
	double	dir_x; //direction horizontally player's facing
	double	dir_y; //direction vertically player's facing
	double	posx; //player's horizontal position in world
	double	posy; //player's vertical position in world
	double	planex; //horizontal vision size
	double	planey; //vertical vision size
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	camera_x; //horizontal position in the camera's plane
	double	ray_dir_x; //horizontal direction of the ray in the world
	double	ray_dir_y; //vertical direction of the ray in the world
	int		map_x; //horizontal map's cell where the ray is
	int		map_y; //vertical map's cell where the ray is
	double	side_dist_x; //horizontal distance from ray to next gridline
	double	side_dist_y; //vertical distance from ray to next gridline
	double	delta_dist_x; //ray goes horizontaly to cross an entire cell
	double	delta_dist_y; //ray goes vertically to cross an entire cell
	double	perp_wall_dist; //perpendicalr distance from camera to wall
	int		step_x; //horizontal step's direction
	int		step_y; //vertical step's direction
	int		side; //wall was hit (0 vertical - X, 1 horizontal - Y)
}	t_ray;

typedef struct s_wall
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	tex_x;
}	t_wall;

typedef struct s_map
{
	char	**map; //to store the result of the linked list
	int		width;
	int		height;
}	t_map;

typedef struct s_tex
{
	int		defined;
	char	*path;
	char	*addr;
	void	*img;
	int		height;
	int		width;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_color
{
	int		defined;
	char	*code;
	int		rgb[3];
	int		color;
}			t_color;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	int			win_width;
	int			win_height;
	double		tex_pos;
	t_tex		texture[4]; //[0]NO, [1]SO, [2]WE, [3]EA
	t_player	player;
	t_map		map;
	t_color		floor_color;
	t_color		sky_color;
	t_ray		ray;
	t_img		screen;
}	t_game;

//linked list to store the map from the file
typedef struct s_map_file
{
	char				*line;
	struct s_map_file	*next;
}				t_map_file;

#endif