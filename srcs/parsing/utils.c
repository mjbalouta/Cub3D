#include "cub3d.h"

/**
 * @brief frees double char** arrays
 * 
 * @param strs 
 */
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

/**
 * @brief counts the strings in a double char**
 * 
 * @param strs 
 * @return int 
 */
int	count_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

/**
 * @brief counts the size of the map's linked list
 * 
 * @param map_list 
 * @return int 
 */
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
