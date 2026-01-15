#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/get-next-line/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/libftprintf.h"
# include <errno.h>
# include <math.h>

# define WALLS_ERROR "The map must be surrounded by walls (1)."
# define ERROR_IDENTIFIER "Invalid identifier.  \
Expected definitions of NO, SO, WE, EA and F, C first and then the map."
# define COLOR_FORMAT_ERROR "Invalid color code.  \
Must be between 0 and 255 only and without spaces in between numbers."
# define RGB_ERROR "Invalid color code. Must be R,G,B format."
# define SPEED 0.1

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
	double	time;
	double	oldTime;
}	t_player;

typedef	struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;


typedef	struct s_ray
{
	double	camera_x; //horizontal position in the camera's plane
	double	ray_dir_x; //horizontal direction of the ray in the world
	double	ray_dir_y; //vertical direction of the ray in the world
	int		map_x; //horizontal map's cell where the ray is
	int		map_y; //vertical map's cell where the ray is
	double	side_dist_x; //horizontal distance from ray to next gridline
	double	side_dist_y; //vertical distance from ray to next gridline
	double	delta_dist_x; //how much the ray goes horizontaly to cross an entire cell
	double	delta_dist_y; //how much the ray goes vertically to cross an entire cell
	double	perp_wall_dist; //perpendicalr distance from camera to wall
	int		step_x; //horizontal step's direction
	int		step_y; //vertical step's direction
	int		side; //which type of wall was hit (0 vertical - X, 1 horizontal - Y)
}	t_ray;

typedef	struct s_wall
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