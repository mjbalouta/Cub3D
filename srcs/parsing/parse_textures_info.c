#include <sys/stat.h>
#include "cub3d.h"

/**
 * @brief this function defines the path to the respective texture
 * 
 * @param direction 
 * @param game 
 * @param path 
 */
void	define_texture(int direction, t_game *game, char *line, int i)
{
	if (game->texture[direction].defined == 1)
	{
		free(line);
		print_exit_free(DUPLICATED_TEX_ERROR, 1, game);
	}
	game->texture[direction].defined = 1;
	while (line[i] && !is_whitespace(line[i]))
		i++;
	while (line[i] && is_whitespace(line[i]))
		i++;
	game->texture[direction].path = ft_strtrim(line + i, "\n");
}

/**
 * @brief identify which direction to redirect the definition
 * 
 * @param line 
 * @param i 
 * @param game 
 */
void	identify_direction(char *line, int i, t_game *game)
{
	if ((line[i] == 'N' && line[i + 1] == 'O'
			&& is_whitespace(line[i + 2]))
		|| (line[i] == 'N' && is_whitespace(line[i + 1])))
		define_texture(0, game, line, i);
	else if ((line[i] == 'S' && line[i + 1] == 'O'
			&& is_whitespace(line[i + 2]))
		|| (line[i] == 'S' && is_whitespace(line[i + 1])))
		define_texture(1, game, line, i);
	else if ((line[i] == 'W' && line[i + 1] == 'E'
			&& is_whitespace(line[i + 2]))
		|| (line[i] == 'W' && is_whitespace(line[i + 1])))
		define_texture(2, game, line, i);
	else if ((line[i] == 'E' && line[i + 1] == 'A'
			&& is_whitespace(line[i + 2]))
		|| (line[i] == 'E' && is_whitespace(line[i + 1])))
		define_texture(3, game, line, i);
	else
	{
		free(line);
		print_exit_free(ERROR_IDENTIFIER, 1, game);
	}
}

/**
 * @brief this function detects which direction is written in the line
 * 
 * @param line 
 * @param game 
 * @return int 
 */
void	parse_texture_line(char *line, t_game *game, int i)
{
	if (line[i] && line[i + 1] && line[i + 2])
		identify_direction(line, i, game);
	else
	{
		free(line);
		print_exit_free(ERROR_IDENTIFIER, 1, game);
	}
}

/**
 * @brief checks if the texture's path extension is .xpm
 * 
 * @param path 
 */
void	check_path_name(char *path, t_game *game)
{
	char	*extension;
	char	*file;

	file = ft_strrchr(path, '/');
	file++;
	if (ft_strlen(file) <= 4)
		print_exit_free(XPM_ERROR, 1, game);
	extension = ft_strrchr(path, '.');
	if (!extension)
		print_exit_free(XPM_ERROR, 1, game);
	if (ft_strncmp(extension, ".xpm", 5) != 0)
		print_exit_free(XPM_ERROR, 1, game);
}

/**
 * @brief verifies if all the textures have been defined and if they're
 * path is valid
 * 
 * @param game 
 * @return int 
 */
void	verify_defined_textures(t_game *game)
{
	int			i;
	int			fd;

	i = -1;
	fd = -1;
	while (++i < 4)
	{
		if (game->texture[i].defined != 1)
			print_exit_free(NO_TEXTURE_ERROR, 1, game);
		if (!game->texture[i].path
			|| ft_strncmp(game->texture[i].path, "", 1) == 0)
			print_exit_free(TEX_PATH_ERROR, 1, game);
		check_path_name(game->texture[i].path, game);
		fd = open(game->texture[i].path, __O_DIRECTORY);
		if (fd >= 0)
		{
			close(fd);
			print_exit_free(TEX_DIRECTORY_ERROR, 1, game);
		}
		fd = open(game->texture[i].path, O_RDONLY);
		if (fd < 0)
			print_exit_free(OPEN_PATH_ERROR, 1, game);
		close(fd);
	}
}
