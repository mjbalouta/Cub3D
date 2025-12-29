#include "cub3d.h"

/**
 * @brief attributes the color to the respective place
 * 
 * @param game 
 * @param i 
 * @param line 
 * @param place 
 */
void	define_colors(t_game *game, int i, char *line, int place)
{
	if (place == 1)
	{
		game->floor_color = 1;
		while (line[i] && line[i] == ' ')
			i++;
		game->floor_code = ft_strtrim(line + i, "\n");
	}
	else if (place == 2)
	{
		game->sky_color = 1;
		while (line[i] && line[i] == ' ')
			i++;
		game->sky_code = ft_strtrim(line + i, "\n");
	}
}
/**
 * @brief identifies the place in which to apply the color
 * 
 * @param line 
 * @param game 
 * @return int 
 */
int parse_color_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && line[i + 1])
	{
		if (line[i] == 'F' && line[i + 1] == ' ')
			define_colors(game, i + 1, line, 1);
		else if (line[i] == 'C' && line[i + 1] == ' ')
			define_colors(game, i + 1, line, 2);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
/**
 * @brief verifies if the color codes are between 0 and 255
 * 
 * @param color_codes 
 * @return int 
 */
int	verifies_numbers(char **color_codes)
{
	int	nr;
	int	i;

	i = 0;
	while (color_codes[i])
	{
		nr = ft_atoi(color_codes[i]);
		if (nr < 0 || nr > 225)
			return (1);
		i++;
	}
	return (0);
}
/**
 * @brief verifies if the color code is a valid one
 * 
 * @param game 
 * @param code_str 
 * @return int 
 */
int	validate_color_codes(t_game *game, char *code_str)
{
	int		i;
	char	**color_codes;

	i = 0;
	if (game->floor_color != 1 || game->sky_color != 1)
		return (1);
	while (code_str[i])
	{
		if (!ft_isdigit(code_str[i]) && code_str[i] != ',')
			return (1);
		i++;
	}
	color_codes = ft_split(code_str, ',');
	if (!color_codes)
		return (1);
	if (count_strings(color_codes) != 3 || verifies_numbers(color_codes) != 0)
		return (free_arrays(color_codes), 1);
	free_arrays(color_codes);
	return (0);
}
/**
 * @brief calls functions to validate the lines that define the colors of the
 * ceiling and the floor
 * 
 * @param line 
 * @param game 
 * @return int 
 */
int	validate_colors(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (parse_color_line(line, game) != 0)
			return (free(line), 1);
		free(line);
		i++;
	}
	if (validate_color_codes(game, game->floor_code) || validate_color_codes(game, game->sky_code))
		return (1);
	return (0);
}