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
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Unable to open the file.\n"), -1);
	//alterar para outra função?
	//parsing definitions of textures
	while (i < 4)
	{
		line = get_next_line(fd);
		if (!line[i] && validate_textures(line, game) != 0)
			return (ft_printf("Error\nInvalid identifier.\n"), 1);
		i++;
		free(line);
	}
	i = 0;
	//parsing floor and ceiling colors
	while (i < 2)
	{
		line = get_next_line(fd);
		if (!line[i] && validate_colors(line, game) != 0)
			return (ft_printf("Error\nInvalid identifier.\n"), 1);
		i++;
		free(line);
	}
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
