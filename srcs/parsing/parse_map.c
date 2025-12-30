#include "cub3d.h"

char	**create_map_copy(t_game *game, int fd)
{
	char	*line;
	int		size;
	char	**map_copy;
	int		i;

	//criar primeiro uma linkedlist para fazer uma cópia dinâmica do mapa
	//depois calcular o list size
	//converter para um char ** para ser mais fácil executar as verificações
	//esta forma é melhor do que guardar a linha em que começa o mapa e abrir o
	//ficheiro duas vezes para construir o char **?
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	ft_strlcpy(map_copy[i], line, ft_strlen(line) + 1);
	game->map->height++;
	i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (-1);
		ft_strlcpy(map_copy[i], line, ft_strlen(line) + 1);
		game->map->height++;
		i++;
	}
	return (map_copy);
}

int	validate_map(t_game *game, int fd)
{
	int	height;

	height = count_map_lines(fd);
	ft_printf("\n%d\n", height);
	(void)*game;
	return (0);
}