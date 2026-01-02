#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/get-next-line/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/libftprintf.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_map
{
	char	**map; //to store the result of the linked list
	int		width;
	int		height;
}	t_map;

typedef struct s_tex
{
	int		defined;
    char    *path;
    void    *img;
    int     height;
    int     width;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_color
{
	int		defined;
	char	*code;
	int		rgb[3];
}			t_color;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	int			collected;
	int			win_width;
	int			win_height;
	t_tex		texture[4]; //[0]NO, [1]SO, [2]WE, [3]EA
	t_player	player;
	t_map		map;
	t_color		floor_color;
	t_color		sky_color;
}	t_game;

//linked list to store the map from the file
typedef struct s_map_file
{
	char				*line;
	struct s_map_file	*next;
}				t_map_file;

#endif