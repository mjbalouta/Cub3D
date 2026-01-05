#include "cub3d.h"

/**
 * @brief checks if there are invalid chars in the map
 * 
 * @param game 
 */
void	validate_chars(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	int		start;

	map = game->map.map;
	i = 0;
	start = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] == '\n' && start == 1)
			print_exit_free("Error\nThe map can't contain an empty"
				" line in the middle.", 1, game);
		while (map[i][j] && map[i][j] != '\n')
		{
			start = 1;
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N' ||
				map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W' ||
				map[i][j] == ' ')
					j++;
			else
				print_exit_free("Error\nThe map contains invalid characters."
					" Only 0, 1, N, S, E, W are valid.", 1, game);
		}
		i++;
	}
}
/**
 * @brief returns 1 if tile is different than a wall (1)
 * 
 * @param tile 
 * @return int 
 */
int	checks_walkable_chars(char tile)
{
	if (tile == '0' || tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
		return (1);
	return (0);
}

/**
 * @brief checks if the map is surrounded by walls
 * 
 * @param game 
 */
void	check_walls(t_game *game)
{
	int		line_size;
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = game->map.map;
	while (map[++i])
	{
		line_size = ft_strlen(map[i]) - 1;
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if ((i == 0 || i == game->map.height - 1 || j == 0
				|| j == line_size - 1) && map[i][j] != '1' && map[i][j] != ' ')
				print_exit_free("Error\nThe map must be surrounded by walls (1)", 1, game);
			if (map[i][j] == ' ' && i != game->map.height - 1 && map[i + 1][j] != '1'
				&& map[i + 1][j] != ' ')
				print_exit_free("Error\nThe map must be surrounded by walls (1)", 1, game);
			if (checks_walkable_chars(map[i][j]) && (map[i - 1][j] == ' '
				|| map[i + 1][j] == ' ' || map[i][j - 1] == ' '
				|| map[i][j + 1] == ' '))
				print_exit_free("Error\nThe map must be surrounded by walls (1)", 1, game);				
		}
	}
}

void	check_players(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	int		players;

	map = game->map.map;
	i = 0;
	players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				players++;
			j++;
		}
		i++;
	}
	if (players > 1)
		print_exit_free("Error\nYou can only have one player in your map.", 1, game);
	else if (players < 1)
		print_exit_free("Error\nYou must have one player in your map.", 1, game);
}

/**
 * @brief calls the validation functions to verify the map
 * 
 * @param game 
 * @param fd 
 * @return int 
 */
int	validate_map(t_game *game, int fd)
{
	t_map_file	*map_list;
	int			size;

	create_linked_list(game, &map_list, fd);
	size = list_size(map_list);
	create_map_copy(&map_list, game, size);
	free_list(&map_list);
	validate_chars(game);
	check_players(game);
	check_walls(game);
	return (0);
}
