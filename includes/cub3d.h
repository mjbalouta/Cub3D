#ifndef PROTOTYPES_H
# define PROTOTYPES_H

#include "structs.h"

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
	int			win_width;
	int			win_height;
	t_tex		texture[4]; //[0]NO, [1]SO, [2]WE, [3]EA
	t_player	player;
	t_map		map;
	int			collected;
	t_color		floor_color;
	t_color		sky_color;
}	t_game;

//--------------------------PARSING--------------------------

int		validate_filename(char *str);
void	validate_args(int ac, char **av);
void	validate_file(char *file, t_game *game);
void	parse_file_info(char *file, t_game *game);
int		parse_texture_line(char *line, t_game *game);
int		define_texture(int direction, t_game *game, char *line, int i);
int		parse_line(char *line, t_game *game);
void	check_extension(char *path);
void	verify_defined_textures(t_game *game);
int		validate_textures(t_game *game, int fd);
void	define_colors(t_game *game, int i, char *line, int place);
int		parse_color_line(char *line, t_game *game);
void	validate_color_codes(t_game *game, char *code_str, char option);
int		validate_colors(t_game *game, int fd);
void	verify_numbers(char **color_codes, t_game *game, char option);
void	free_arrays(char **strs);
int		count_strings(char **strs);
int		validate_map(t_game *game, int fd);
char	**create_map_copy(t_game *game, int fd);

//---------------------------CLEAN---------------------------

void	print_message_exit(char *message, int exit_code);

//--------------------------INIT-----------------------------

void	init_game(t_game *game);
void	init_texture_struct(t_game *game);
void	init_color_struct(t_game *game);

#endif
