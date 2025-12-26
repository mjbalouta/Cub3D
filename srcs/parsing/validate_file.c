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
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Unable to open the file.\n"), -1);
	line = get_next_line(fd);
	if (parse_line(line, game) != 0)
		return (ft_printf("Error\nInvalid identifier.\n"), 1);
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
