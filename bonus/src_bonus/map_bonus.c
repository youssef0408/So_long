/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:50:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 04:05:13 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

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

void	init_map(t_game *game)
{
	game->map = (t_map){
		.height = 0,
		.width = 0,
		.has_p = false,
		.has_e = false,
		.has_m = false,
		.count_c = 0,
		.items = 0,
		.grid = (char **)malloc(sizeof(char *) * (100)),
	};
}

void	populate_row(char *str, size_t row_idx, t_map *map)
{
	map->grid[row_idx] = str;
}
