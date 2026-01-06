#ifndef PROTOTYPES_H
# define PROTOTYPES_H

#include "structs.h"

//--------------------------PARSING--------------------------

int		validate_filename(char *str);
void	validate_args(int ac, char **av, t_game *game);
void	validate_file(char *file, t_game *game);
void	parse_file_info(char *file, t_game *game);
void	parse_texture_line(char *line, t_game *game, int i);
void	define_texture(int direction, t_game *game, char *line, int i);
int		parse_line(char *line, t_game *game);
void	check_extension(char *path, t_game *game);
void	verify_defined_textures(t_game *game);
void	define_colors(t_game *game, int i, char *line, int place);
void	parse_color_line(char *line, t_game *game, int i);
void	validate_color_codes(t_game *game, char *code_str, char option);
void	verify_numbers(char **color_codes, t_game *game, char option);
void	free_arrays(char **strs);
int		count_strings(char **strs);
int		validate_map(t_game *game, int fd);
void	create_linked_list(t_game *game, t_map_file **map_list, int fd);
void	create_map_copy(t_map_file **map_list, t_game *game, int size);
int		list_size(t_map_file *map_list);
void	check_players(t_game *game);
int		tracks_identified_info(t_game *game);
int		is_whitespace(char a);
int		count_digits_string(char *str);
int		count_digits_numbers(int num);


//---------------------------CLEAN---------------------------

void	print_message_exit(char *message, int exit_code);
void	free_mem(t_game *game);
void	print_exit_free(char *message, int exit_code, t_game *game);
void	free_list(t_map_file **map_list);

//--------------------------INIT-----------------------------

void	init_game(t_game *game);
void	init_texture_struct(t_game *game);
void	init_color_struct(t_game *game);

#endif
