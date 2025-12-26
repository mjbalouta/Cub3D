/**
 * @brief this function verifies if the extension is .cub
 * 
 * @param str 
 * @return int 
 */
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

/**
 * @brief this function validates the args of the prompt
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int validate_args(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf("The program must be run with only a .cub file"), 1);
	if (validate_file_name(av[1]) != 0)
		return (ft_printf("The program must be run with a something.cub file.\n"), 1);
	return (0);
}
