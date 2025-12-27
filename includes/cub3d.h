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
	int		defined;
    char    *path;
    char    *img;
    int     height;
    int     width;
}	t_tex;

typedef struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_tex		texture[4]; //[0]NO, [1]SO, [2]WE, [3]EA
	t_player	*player;
	t_map		*map;
	int			collected;
	int			floor_color;
	char		*floor_code;
	int			sky_color;
	char		*sky_code;
}	t_game;

//--------------------------PARSING--------------------------

int		validate_filename(char *str);
int		validate_args(int ac, char **av);
int		validate_file(char *file, t_game *game);
int		parse_file_info(char *file, t_game *game);
int		parse_texture_line(char *line, t_game *game);
int		define_texture(int direction, t_game *game, char *line, int i);
int		parse_line(char *line, t_game *game);
void	verify_defined_textures(t_game *game);
int		validate_textures(t_game *game, int fd);
void	define_colors(t_game *game, int i, char *line, int place);
int		parse_color_line(char *line, t_game *game);
int		validate_color_codes(t_game *game, char *code_str);
int		validate_colors(char *line, t_game *game);
void	free_arrays(char **strs);
int		count_strings(char **strs);

//---------------------------CLEAN---------------------------

void	print_message_exit(char *message, int exit_code);

#endif