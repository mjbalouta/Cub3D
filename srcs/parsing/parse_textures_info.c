#include <sys/stat.h>
#include "cub3d.h"

/**
 * @brief this function defines the path to the respective texture
 * 
 * @param direction 
 * @param game 
 * @param path 
 */
void	define_texture(int direction, t_game *game, char *line)
{
	char	*path;

	game->texture[direction].defined = 1;
	//o path começa sempre por um ponto?
	path = ft_strchr(line, '.');
	game->texture[direction].path = path;
}
/**
 * @brief this function detects which direction is written in the line
 * 
 * @param line 
 * @param game 
 * @return int 
 */
int parse_line(char *line, t_game *game)
{
	//Não pode ser hardcoded, acho que são permitidos espaços na posição 0...
	if ((line[0] == "N" && line[1] == "O" && line[3] == " ") || line[0] == "N" && line[1] == " ")
		define_texture(0, game, line);
	else if ((line[0] == "S" && line[1] == "O" && line[3] == " ") || line[0] == "S" && line[1] == " ")
		define_texture(1, game, line);
	else if ((line[0] == "W" && line[1] == "E" && line[3] == " ") || line[0] == "W" && line[1] == " ")
		define_texture(2, game, line);
	else if ((line[0] == "E" && line[1] == "A" && line[3] == " ") || line[0] == "E" && line[1] == " ")
		define_texture(3, game, line);
	else
		return (1);
	return (0);
}

int	verify_defined_textures(t_game *game)
{
	int			i;
	int			fd;

	i = 0;
	fd = -1;
	while (i < 4)
	{
		if (game->texture[i].defined != 1)
			return (1);
		//verificar se a extensão da imagem é xpm?
		fd = open(game->texture[i].path, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			return (ft_printf("Error\nInvalid path in .cub file"), 1);
		}
		i++;
		close(fd);
	}
}
