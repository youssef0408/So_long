/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:01:04 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/12 17:41:57 by yothmani         ###   ########.fr       */
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

void	free_file(char *str, int fd)
{
	free(str);
	str = NULL;
	close(fd);
}

char	*generate_file_name(void)
{
	char	*temp;
	char	*file_name;
	int		i;
	char	*file_num;

	i = rand() % 5;
	file_num = ft_itoa(i);
	temp = ft_strjoin("src/maps/map", file_num);
	file_name = ft_strjoin(temp, ".ber");
	free(temp);
	free(file_num);
	temp = NULL;
	file_num = NULL;
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

void	full_free(t_game game, char *file_name)
{
	free(file_name);
	free_map(game.map.grid, game.map.height);
}
