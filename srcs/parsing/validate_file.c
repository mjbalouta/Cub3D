#include "cub3d.h"

/**
 * @brief this function opens the .cub file, reads it line by line and calls
 * parse_line() to verify each line
 * 
 * @param file 
 * @param game 
 * @return int 
 */
int	parse_file_info(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_message_exit("Unable to open the file.", 1);
	if (validate_textures(game, fd) != 0)
		print_message_exit("Error\nInvalid direction identifier.", 1);
	if (validate_colors(game, fd) != 0)
		print_message_exit("Error\nInvalid color identifier.", 1);
	return (0);
}
/**
 * @brief this function calls other functions in order to validate the file
 * 
 * @param file 
 * @param game 
 * @return int 
 */
int	validate_file(char *file, t_game *game)
{
	if (parse_file_info(file, game) != 0)
		return (1);
	return (0);
}
