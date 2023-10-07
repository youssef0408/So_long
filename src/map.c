/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:50:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/07 15:59:34 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	real_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->has_p = false;
	map->has_e = false;
	map->count_c = 0;
}

void	init_map2(t_game *game)
{
	t_map	map;

	map = (t_map)
	{
		.height = 0,
		.width = 0,
		.has_p = false,
		.has_e = false,
		.count_c = 0,
	};
	game->map = map;
}

void	populate_row(char *str, size_t row_idx, t_map *map)
{
	map->grid[row_idx] = str;
}

void	show_grid(t_map *map)
{
	size_t	i;
	size_t	j;
	char	obj;

	i = 0;
	printf("\n");
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			obj = map->grid[i][j];
			if (i == 0 || i == map->height - 1)
				printf("█");
			else if (obj == '0')
				printf(" ");
			else if (obj == '1')
				printf("█");
			else if (obj == 'M')
				printf("*");
			else
				printf("%c", obj);
			j++;
		}
		printf("\n");
		i++;
	}
}
