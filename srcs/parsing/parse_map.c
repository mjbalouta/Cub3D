#include "cub3d.h"

//criar primeiro uma linkedlist para fazer uma cópia dinâmica do mapa
//depois calcular o list size
//converter para um char ** para ser mais fácil executar as verificações
//esta forma é melhor do que guardar a linha em que começa o mapa e abrir o
//ficheiro duas vezes para construir o char **?

// void	validate_characters(t_game *game)
// {

// }

int	validate_map(t_game *game, int fd)
{
	t_map_file	*map_list;
	int			size;

	create_linked_list(game, &map_list, fd);
	size = list_size(map_list);
	create_map_copy(&map_list, game, size);
	free_list(&map_list);
	return (0);
}
