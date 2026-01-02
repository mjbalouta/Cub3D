#include "cub3d.h"

/**
 * @brief this function opens the .cub file, reads it line by line and calls
 * parse_line() to verify each line
 * 
 * @param file 
 * @param game 
 * @return void 
 */
void	parse_file_info(char *file, t_game *game)
{
	int		fd;

	//!!!!!!Except for the map content which always has to be the last, each type of element can be set in any order in the file.!!!!!!
	//!!!!!!Except for the map, each type of information from an element can be separated by one or more spaces.!!!!!!
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_exit_free("Unable to open the file.", 1, game);
	if (validate_textures(game, fd) != 0)
		print_exit_free("Error\nInvalid direction identifier.", 1, game);
	if (validate_colors(game, fd) != 0)
		print_exit_free("Error\nInvalid color identifier.", 1, game);
	validate_map(game, fd);
}
/**
 * @brief this function calls other functions in order to validate the file
 * 
 * @param file 
 * @param game 
 * @return void 
 */
void	validate_file(char *file, t_game *game)
{
	parse_file_info(file, game);
}
