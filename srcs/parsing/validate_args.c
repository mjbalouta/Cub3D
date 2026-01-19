#include "cub3d.h"

/**
 * @brief this function verifies if the extension is .cub
 * 
 * @param str 
 * @return int
 */
int	validate_filename(char *str)
{
	char	*ext;

	if (ft_strlen(str) <= 4)
		return (1);
	ext = ft_strrchr(str, '.');
	if (!ext)
		return (1);
	ext--;
	if (ext[0] == '/')
		return (1);
	ext++;
	if (ft_strncmp(ext, ".cub", 5) != 0)
		return (1);
	return (0);
}

/**
 * @brief this function validates the args of the prompt
 * 
 * @param ac 
 * @param av 
 * @return void 
 */
void	validate_args(int ac, char **av, t_game *game)
{
	if (ac != 2 || validate_filename(av[1]) != 0)
		print_exit_free(ARGS_ERROR, 1, game);
}
