#include "cub3d.h"

int	validate_file_name(char *str)
{
	char *ext;

	if (ft_strlen(str) <= 4)
		return (1);
	ext = ft_strrchr(str, '.');
	if (!ext)
		return (1);
	if (ft_strncmp(ext, ".cub", 5) != 0)
		return (1);
	return (0);
}
