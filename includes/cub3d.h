#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structs.h"
# include "../minilibx-linux/mlx.h"

//--------------------------PARSING--------------------------

int		validate_filename(char *str);
void	validate_args(int ac, char **av, t_game *game);
void	validate_file(char *file, t_game *game);
void	parse_file_info(char *file, t_game *game);
void	parse_texture_line(char *line, t_game *game);
void	define_texture(int direction, t_game *game, char *line, int i);
int		parse_line(char *line, t_game *game);
void	check_extension(char *path, t_game *game);
void	verify_defined_textures(t_game *game);
int		validate_textures(t_game *game, int fd);
void	define_colors(t_game *game, int i, char *line, int place);
void	parse_color_line(char *line, t_game *game);
void	validate_color_codes(t_game *game, char *code_str, char option);
int		validate_colors(t_game *game, int fd);
void	verify_numbers(char **color_codes, t_game *game, char option);
void	free_arrays(char **strs);
int		count_strings(char **strs);
int		validate_map(t_game *game, int fd);
char	**create_map_copy(t_game *game, int fd);

//---------------------------CLEAN---------------------------

void	print_message_exit(char *message, int exit_code);
void	free_mem(t_game *game);
void	print_exit_free(char *message, int exit_code, t_game *game);

//--------------------------INIT-----------------------------

void	init_game(t_game *game);
void	init_texture_struct(t_game *game);
void	init_color_struct(t_game *game);
void	init_mlx(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
void	load_textures(t_game *game);

//------------------------RAYCASTING-------------------------.

//void	start_ray(t_game *game);

#endif
