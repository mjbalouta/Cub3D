#include "cub3d.h"

int	count_digits_string(char *str)
{
	int	i;
	int	count_digits;

	i = 0;
	count_digits = 0;
	while (str[i])
	{
		if (ft_isdigit((int)(str[i])))
			count_digits++;
		i++;
	}
	return (count_digits);
}

int	count_digits_numbers(int num)
{
	int	nr_digits;

	nr_digits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		nr_digits++;
	}
	return (nr_digits);
}
