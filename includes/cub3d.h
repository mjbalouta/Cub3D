#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

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
void	identify_direction(char *line, int i, t_game *game);


//---------------------------CLEAN---------------------------

void	print_message_exit(char *message, int exit_code);
void	free_mem(t_game *game);
void	print_exit_free(char *message, int exit_code, t_game *game);
void	free_list(t_map_file **map_list);

//--------------------------INIT-----------------------------

void	init_game(t_game *game);
void	init_texture_struct(t_game *game);
void	init_color_struct(t_game *game);
void	init_mlx(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
void	load_textures(t_game *game);
int		render(t_game *game);

//------------------------RAYCASTING--------------------------

void	start_ray(t_game *game);
void	finalize_colors(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	cast_ray(t_game *game, int x, t_ray *ray);
void	draw_column(t_game *game, int x, t_ray *ray);
void	calculate_wall_distance(t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_step_and_side_dist(t_game *game, t_ray *ray);
void	draw_ceiling_floor(t_game *game, int x, t_wall *wall);
void	draw_wall_column(t_game *game, int x, t_ray *ray, t_wall *wall);
int		get_texture_color(t_tex *texture, int x, int y);
void	calculate_wall_height(t_ray *ray, t_game *game, t_wall *wall);
void	calculate_texture_x(t_ray *ray, t_game *game, t_wall *wall);
int		get_texture_index(t_ray *ray);

//-------------------------GAME-------------------------------

void	find_and_set_player(t_game *game);
void	set_player_direction(t_game *game, char orientation);
void	set_weast_east(t_game *game, char orientation);
void	set_north_south(t_game *game, char orientation);
int		handle_keypress(int keycode, t_game *game);
void	init_img(t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
void	move_player(t_game *game);
void	rotate(t_game *game, double angle);
void	move_up(t_game *game, double new_y, double new_x);
void	move_down(t_game *game, double new_y, double new_x);
void	move_right(t_game *game, double new_y, double new_x);
void	move_left(t_game *game, double new_y, double new_x);

#endif
