/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:01:04 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/09 17:53:12 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

// size_t	get_map_height(char *file_name)
// {
// 	int		fd;
// 	char	*buffer;
// 	size_t	height;

// 	height = 1;
// 	fd = open_file(file_name);
// 	if (fd < 0)
// 		return (0);
// 	while (read(fd, &buffer, 1) > 0)
// 	{
// 		if (&buffer == '\n')
// 			height++;
// 	}
// 	close(fd);
// 	return (height);
// }

char	**map_malloc(char **grid, size_t map_size)
{
	grid = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (!grid)
	{
		return (NULL);
	}
	return (grid);
}

void	free_file(char *str, int fd)
{
	free(str);
	str=NULL;
	close(fd);
}

char	*generate_file_name(void)
{
	char	*file_name1;
	char	*file_name;
	int		i;

	// char	*temp;
	// file_name = malloc(1);
	// if (file_name == NULL)
	// 	return (NULL);
	// file_name[0] = '\0';
	// free(file_name);
	// if (temp == NULL)
	// 	return (NULL);
	// file_name = temp;
	// if (map_rand_str == NULL)
	// {
	// 	free(file_name);
	// 	return (NULL);
	// }
	i = rand() % 4;
	char *idx = ft_itoa(i);
		file_name1 = ft_strjoin("src/maps/map", idx);
	file_name = ft_strjoin(file_name1, ".ber");
	//  free(file_name);
	// free(map_rand_str);
	// if (temp == NULL)
	// 	return (NULL);
	// file_name = temp;
	// temp = ft_strjoin(file_name, ".ber");
	free(file_name1);
	free(idx);
	file_name1=NULL;
	idx=NULL;
	// if (temp == NULL)
	// 	return (NULL);
	// file_name = temp;
	return (file_name);
}

void	free_map(char **grid, size_t height)
{
	size_t	i;

	if (grid)
	{
		i = 0;
		while (i < height)
		{
			if (grid[i])
			{
				free(grid[i]);
				grid[i] = NULL;
			}
			i++;
		}
		free(grid);
	}
}
