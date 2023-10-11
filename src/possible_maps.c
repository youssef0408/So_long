/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:31 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/11 15:27:45 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

bool	is_position_valid(t_game *game, size_t x, size_t y)
{
	if (x >= game->map.width || y >= game->map.height || x < 0 || y < 0 ||
		!(game->map.grid[y][x] == '0' || game->map.grid[y][x] == 'P' ||
			game->map.grid[y][x] == 'C'||game->map.grid[y][x] == 'M'))
		return (true);
	return (false);
}

void	path_finder(t_game *game, size_t x, size_t y)
{
	if (game->map.grid[y][x] == 'E')
	{
		game->map.is_possible = 1;
		return ;
	}
	if (game->map.grid[y][x] == 'C')
	{
		game->map.items--;
	}
	if (is_position_valid(game, x, y) == true)
		return ;
	game->map.grid[y][x] = 'V';
	path_finder(game, x, y - 1);
	path_finder(game, x, y + 1);
	path_finder(game, x + 1, y);
	path_finder(game, x - 1, y);
}

bool	map_is_playable(t_game *game)
{
	int	startX;
	int	startY;
	int	width;
	int	height;

	startX = game->map.p_x;
	startY = game->map.p_y;
	width = game->map.width;
	height = game->map.height;
	game->map.is_possible = 0;
	game->map.items = game->map.count_c;
	path_finder(game, startX, startY);
	if(game->map.is_possible == 1 && game->map.items == 0)
	{
		free_map(game->map.grid, game->map.height);
		return(true);
	}
	return(false);
}
