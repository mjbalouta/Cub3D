#include "cub3d.h"

//criar primeiro uma linkedlist para fazer uma cópia dinâmica do mapa
//depois calcular o list size
//converter para um char ** para ser mais fácil executar as verificações
//esta forma é melhor do que guardar a linha em que começa o mapa e abrir o
//ficheiro duas vezes para construir o char **?

int	check_valid_element(char map_element)
{
	if (map_element == '0' || map_element == '1' || map_element == 'N' ||
		map_element == 'S' || map_element == 'E' || map_element == 'W')
			return (1);
	return (0);
}

void	validate_characters(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	int		line_size;

	//!!!The map must be parsed as it looks in the file. 
	//Spaces are a valid part of the map and are up to you to handle.
	//You must be able to parse any kind of map, as long as it respects the rules of the map.
	map = game->map.map;
	i = 0;
	j = 0;
	while (map[i])
	{
		line_size = ft_strlen(map[i]);
		while (map[i][j])
		{
			// if (map[i][j] == ' ')
			// {
			// 	j++;
			// 	continue ;
			// }
			if (map[i][j] == '\n')
				break ;
			if (!check_valid_element(map[i][j]) && map[i][j] != ' ')
			{
				ft_printf("First check\n");
				print_exit_free("Error\nThe map contains invalid characters. Only 0, 1, N, S, E, W are valid.", 1, game);
			}
			if ((i == 0 || i == game->map.height - 1 || j == 0
				|| j == line_size - 1) && map[i][j] != '1' && map[i][j] != ' ')
				{
					ft_printf("Second check\n");
					print_exit_free("Error\nThe map must be surrownded by walls (1)", 1, game);
				}
			if (map[i][j] == ' ' && map[i + 1][j] && map[i + 1][j] != '1' && check_valid_element(map[i + 1][j]))
			{
				ft_printf("Third check\n");
				print_exit_free("Error\nThe map must be surrownded by walls (1)", 1, game);
			}
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
	return (0);
}
