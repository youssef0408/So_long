
#include "so_long.h"

void	init_map(t_map *mat)
{
	mat->height = 0;
	mat->width = 0;
	mat->has_p = false;
	mat->has_e = false;
	mat->count_c = 0;
}

void	populate_row(char *str, size_t row_idx, t_map *map)
{
	// size_t j, i;
	// i = 0;
	// j = 0;
	// while (j < map->width)
	// {
	// 	printf("   %c  ", str[j]);
	// map->grid[row_idx][j] = str[j];
	map->grid[row_idx] = str;
	// 	j++;
	// }
	// while (i < map->width)
	// {
	// 	printf("   grid[%zu][%zu] = %c", row_idx, i, map->grid[row_idx][j]);
	// 	i++;
	// }
	// printf("\n");
}

void	show_grid(t_map *map)
{
	size_t	i;
	size_t	j;
	char	obj;

	i = 0;
	j = 0;
	
	while (i < map->height)
	{
			// printf("\nobj\n = %s", map->grid[i]);
            j=0;
		while (j < map->width)
		{
			obj = map->grid[i][j];
			// printf("\nobj\n = %c", obj);
			if (i == 0 || i == map->height - 1)
				printf("-");
			else if (obj == '0')
				printf(" ");
			else if (obj == '1')
				printf("|");
			else
				printf("%c", obj);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	line_check2(char *str, t_map *mat)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	if (mat->width != real_len(str))
		return (-2);
	if (str[0] != '1' || str[mat->width - 1] != '1')
	{
		return (-8);
	}
	while (str[i] && i < mat->width - 1)
	{
		if (mat->height == 0 && str[i] != '1')
			return (-9);
		else if (str[i] == 'E')
		{
			if (mat->has_e)
				return (-3);
			else
				mat->has_e = true;
		}
		else if (str[i] == 'P')
		{
			if (mat->has_p)
				return (-4);
			else
				mat->has_p = true;
		}
		else if (str[i] == 'C')
		{
			mat->count_c = mat->count_c + 1;
		}
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
			return (-5);
		i++;
	}
	populate_row(str, mat->height, mat);
	mat->height = mat->height + 1;
	return (0);
}

bool	parse_file2(char *file_path, t_map *mat)
{
	int		fd;
	char	*current_line;
	char	*previous_line;
	bool	has_error;
	int		check;
	size_t	i;

	init_map(mat);
	has_error = false;
	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (true);
	}
	current_line = get_next_line(fd);
	if (real_len(current_line) == 0)
	{
		free(current_line);
		close(fd);
		return (true);
	}
	mat->width = real_len(current_line);
	check = line_check2(current_line, mat);
	if (check < 0)
	{
		free(current_line);
		close(fd);
		return (true);
	}
	// printf("%s", current_line);
	while (current_line != NULL && has_error == false)
	{
		previous_line = current_line;
		current_line = get_next_line(fd);
		if (current_line == NULL)
		{
			if (previous_line[mat->width] == '\n')
				return (true);
			while (i < mat->width - 1)
			{
				if (previous_line[i] != '1')
					return (true);
				i++;
			}
			free(current_line);
			close(fd);
			if (mat->count_c == 0 || !mat->has_p || !mat->has_e)
				return (true);
			return (false);
		}
		check = line_check2(current_line, mat);
		if (check < 0)
		{
			has_error = true;
			free(current_line);
			close(fd);
			return (true);
		}
		// printf("%s", current_line);
	}
	return (has_error);
}
