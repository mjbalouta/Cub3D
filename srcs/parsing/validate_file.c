/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:08:52 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:08:53 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief checks if the initial identifiers have been defined
 * (textures and colors)
 * 
 * @param game 
 * @return int 
 */
int	tracks_identified_info(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].defined != 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (game->floor_color.defined != 1 || game->sky_color.defined != 1)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief checks if the identifier belongs to a texture or to a color and
 * calls the function to parse it
 * 
 * @param line 
 * @param game 
 */
void	checks_identifier(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && (is_whitespace(line[i]) || line[i] == '\n'))
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		parse_texture_line(line, game, i);
	else if (line[i] == 'F' || line[i] == 'C')
		parse_color_line(line, game, i);
	else if (line[i] == '1' && tracks_identified_info(game) == 1)
	{
		free(line);
		print_exit_free(MISS_ID_ERROR, 1, game);
	}
	else
	{
		free(line);
		print_exit_free(IDENTIFIER_ERROR, 1, game);
	}
}

/**
 * @brief this function opens the .cub file, reads it line by line and calls
 * parse_line() to verify each line
 * 
 * @param file 
 * @param game 
 * @return void 
 */
void	parse_file_info(t_game *game, int fd)
{
	char	*line;

	while (tracks_identified_info(game) == 1)
	{
		line = get_next_line(fd);
		if (!line)
			print_exit_free(EMPTY_ERROR, 1, game);
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		checks_identifier(line, game);
		free(line);
	}
	verify_defined_textures(game);
	validate_color_codes(game, game->floor_color.code, 'f');
	validate_color_codes(game, game->sky_color.code, 's');
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
	int	fd;

	fd = open(file, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		print_exit_free(DIR_ERROR, 1, game);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_exit_free(OPEN_ERROR, 1, game);
	parse_file_info(game, fd);
}
