/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:50:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/01 01:09:39 by yothmani         ###   ########.fr       */
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
