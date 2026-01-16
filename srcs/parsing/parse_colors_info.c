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
		if (game->floor_color.defined == 1)
		{
			free(line);
			print_exit_free("Duplicated definition of a"
				" color.", 1, game);
		}
		game->floor_color.defined = 1;
		while (line[i] && is_whitespace(line[i]))
			i++;
		game->floor_color.code = ft_strtrim(line + i, "\n");
	}
	else if (place == 2)
	{
		if (game->sky_color.defined == 1)
		{
			free(line);
			print_exit_free("Duplicated definition of a"
				" color.", 1, game);
		}
		game->sky_color.defined = 1;
		while (line[i] && is_whitespace(line[i]))
			i++;
		game->sky_color.code = ft_strtrim(line + i, "\n");
	}
}

/**
 * @brief identifies the place in which to apply the color
 * 
 * @param line 
 * @param game 
 * @return void
 */
void	parse_color_line(char *line, t_game *game, int i)
{
	if (line[i] && line[i + 1])
	{
		if (line[i] == 'F' && is_whitespace(line[i + 1]))
			define_colors(game, i + 1, line, 1);
		else if (line[i] == 'C' && is_whitespace(line[i + 1]))
			define_colors(game, i + 1, line, 2);
		else
		{
			free(line);
			print_exit_free(ERROR_IDENTIFIER, 1, game);
		}
	}
	else
	{
		free(line);
		print_exit_free(ERROR_IDENTIFIER, 1, game);
	}
}

/**
 * @brief verifies if the color codes are between 0 and 255
 * 
 * @param color_codes 
 * @return int 
 */
void	verify_numbers(char **color_codes, t_game *game, char option)
{
	int	nr;
	int	i;
	int	count_before;
	int	count_after;

	i = -1;
	count_after = 0;
	count_before = 0;
	while (color_codes[++i])
	{
		count_before = count_digits_string(color_codes[i]);
		nr = ft_atoi(color_codes[i]);
		count_after = count_digits_numbers(nr);
		if (nr < 0 || nr > 255 || count_before != count_after)
		{
			free_arrays(color_codes);
			print_exit_free(COLOR_FORMAT_ERROR, 1, game);
		}
		if (option == 'f')
			game->floor_color.rgb[i] = nr;
		else if (option == 's')
			game->sky_color.rgb[i] = nr;
	}
}

/**
 * @brief verifies if the color code is a valid one
 * 
 * @param game 
 * @param code_str 
 * @return int 
 */
void	validate_color_codes(t_game *game, char *code_str, char option)
{
	int		i;
	char	**color_codes;

	i = -1;
	if (game->floor_color.defined != 1 || game->sky_color.defined != 1)
		print_exit_free("Colors for floor and ceiling must be"
			" defined.", 1, game);
	while (code_str[++i])
	{
		if (!ft_isdigit(code_str[i]) && code_str[i] != ','
			&& !is_whitespace(code_str[i])
			&& code_str[i] != '+' && code_str[i] != '-')
			print_exit_free(RGB_ERROR, 1, game);
	}
	color_codes = ft_split(code_str, ',');
	if (!color_codes)
		print_exit_free(RGB_ERROR, 1, game);
	if (count_strings(color_codes) != 3)
	{
		free_arrays(color_codes);
		print_exit_free("Invalid color code.", 1, game);
	}
	verify_numbers(color_codes, game, option);
	free_arrays(color_codes);
}
