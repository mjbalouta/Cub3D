#include "cub3d.h"

void	free_arrays(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	count_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	list_size(t_map_file *map_list)
{
	int			size;
	t_map_file	*temp;

	size = 0;
	temp = map_list;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
