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
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_tex
{
    char    *path;
    void    *img;
    int     height;
    int     width;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	t_tex		texture[4];
	t_player	player;
	t_map		map;
	int			floor_color;
	int			sky_color;
	int			win_width;
	int			win_height;
}	t_game;

//--------------------------PARSING--------------------------

int	validate_file_name(char *str);

//--------------------------INIT-----------------------------

void	init_game(t_game *game);

#endif