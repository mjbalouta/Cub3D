#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/get-next-line/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/libftprintf.h"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	int	width;
	int	height;
	int	collectables;
}	t_map;

typedef struct s_tex
{
    char    *path;
    char    *img;
    int     height;
    int     width;
}	t_tex;

typedef struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_tex		texture[4];
	t_player	*player;
	t_map		*map;
	int			collected;
	int			floor_color;
	int			sky_color;
}	t_game;

//--------------------------PARSING--------------------------

int	validate_file_name(char *str);

#endif