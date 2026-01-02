#include "cub3d.h"

//criar primeiro uma linkedlist para fazer uma cópia dinâmica do mapa
//depois calcular o list size
//converter para um char ** para ser mais fácil executar as verificações
//esta forma é melhor do que guardar a linha em que começa o mapa e abrir o
//ficheiro duas vezes para construir o char **?

void	validate_characters(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map.map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' &&
				map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] == 'W' &&
				map[i][j] != ' ')
				print_exit_free("Error\nThe map contains invalid characters. Only 0, 1, N, S, E, W are valid.", 1, game);
			j++;
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	int		line_size;
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = game->map.map;
	while (map[i])
	{
		line_size = ft_strlen(map[i]);
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if ((i == 0 || i == game->map.height - 1 || j == 0
				|| j == line_size - 1) && map[i][j] != '1' && map[i][j] != ' ')
					print_exit_free("Error\nThe map must be surrounded by walls (1)", 1, game);
			if (map[i][j] == ' ' && i != game->map.height - 1 && map[i + 1][j] != '1' && map[i + 1][j] != ' ')
				print_exit_free("Error\nThe map must be surrounded by walls (1)", 1, game);
			j++;
		}
		i++;
	}
}

int	validate_map(t_game *game, int fd)
{
	t_map_file	*map_list;
	int			size;

	create_linked_list(game, &map_list, fd);
	size = list_size(map_list);
	create_map_copy(&map_list, game, size);
	free_list(&map_list);
	validate_characters(game);
	check_walls(game);
	return (0);
}
