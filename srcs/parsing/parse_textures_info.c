#include <sys/stat.h>
#include "cub3d.h"

/**
 * @brief this function defines the path to the respective texture
 * 
 * @param direction 
 * @param game 
 * @param path 
 */
int	define_texture(int direction, t_game *game, char *line, int i)
{
	game->texture[direction].defined = 1;
	while(line[i] && line[i] != ' ')
		i++;
	while(line[i] && line[i] == ' ')
		i++;
	game->texture[direction].path = ft_strtrim(line + i, "\n");
	//no final do path, tenho de verificar se existe mais alguma info? ou a
	//verificação se abre com espaços no meio é suficiente para ser inválido?
	return (0);
}
/**
 * @brief this function detects which direction is written in the line
 * 
 * @param line 
 * @param game 
 * @return int 
 */
int parse_texture_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
			i++;
	if (line[i] && line[i + 1] && line[i + 2])
	{
		if ((line[i] == 'N' && line[i + 1] == 'O'
			&& line[i + 2] == ' ')	|| (line[i] == 'N' && line[i + 1] == ' '))
			define_texture(0, game, line, i);
		else if ((line[i] == 'S' && line[i + 1] == 'O'
				&& line[i + 2] == ' ') || (line[i] == 'S' && line[i + 1] == ' '))
			define_texture(1, game, line, i);
		else if ((line[i] == 'W' && line[i + 1] == 'E'
				&& line[i + 2] == ' ') || (line[i] == 'W' && line[i + 1] == ' '))
			define_texture(2, game, line, i);
		else if ((line[i] == 'E' && line[i + 1] == 'A'
				&& line[i + 2] == ' ') || (line[i] == 'E' && line[i + 1] == ' '))
			define_texture(3, game, line, i);
		else
			return (1);
	}
	else
		return (1);
	return (0);
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

	i = 0;
	fd = -1;
	while (i < 4)
	{
		if (game->texture[i].defined != 1)
			print_message_exit("Not enough textures defined.", 1);
		//verificar se a extensão da imagem é xpm?
		fd = open(game->texture[i].path, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			print_message_exit("Error\nInvalid path in .cub file", 1);
		}
		i++;
		close(fd);
	}
}
/**
 * @brief calls functions to verify the lines that define the textures
 * 
 * @param line 
 * @param game 
 * @return int 
 */
int	validate_textures(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (parse_texture_line(line, game) != 0)
			return (1);
		free(line);
		i++;
	}
	verify_defined_textures(game);
	return (0);
}
