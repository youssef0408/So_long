/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_maps_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:31 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 03:49:12 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

bool	is_position_valid(t_game *game, size_t x, size_t y)
{
	return (x >= 0 && x < game->map.width && y >= 0 && y < game->map.height
		&& game->map.grid[y][x] != 'V' && game->map.grid[y][x] != '1'
				&& game->map.grid[y][x] != 'M');
}

void	path_finder(t_game *game, size_t x, size_t y)
{
	if (!is_position_valid(game, x, y))
		return ;
	if (game->map.grid[y][x] == 'E')
	{
		game->map.is_possible = 1;
		return ;
	}
	if (game->map.grid[y][x] == 'C')
	{
		game->map.items--;
	}
	game->map.grid[y][x] = 'V';
	path_finder(game, x, y - 1);
	path_finder(game, x, y + 1);
	path_finder(game, x + 1, y);
	path_finder(game, x - 1, y);
}

bool	map_is_playable(t_game *game)
{
	game->map.is_possible = 0;
	game->map.items = game->map.count_c;
	path_finder(game, game->map.p_x, game->map.p_y);
	if (game->map.is_possible == 1 && game->map.items == 0)
	{
		free_map(game->map.grid, game->map.height);
		return (true);
	}
	return (false);
}
