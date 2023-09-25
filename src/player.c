/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:08:40 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/24 20:34:38 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// up
void	init_player(t_player *player, t_map map)
{
	player->x = map.p_x;
	player->y = map.p_y;
	player->count_c = 0;
	 player->prev_x = -1;
	 player->prev_y = -1;
}

void	move(t_player *player, int input)
{
	player->prev_x = player->x;
	player->prev_y = player->y;
    
		if (input == 87 || input == 119)
	{
		move_up(player);
	}
	else if (input == 115 || input == 83)
	{
		move_down(player);
	}
	else if (input == 97 || input == 65)
	{
		move_left(player);
	}
	else if (input == 100 || input == 68)
	{
		move_right(player);
	}
}

void	move_up(t_player *player)
{
	player->y = player->y - 1;
}
void	move_down(t_player *player)
{
	player->y = player->y + 1;
}
void	move_left(t_player *player)
{
	player->x = player->x - 1;
}
void	move_right(t_player *player)
{
	player->x = player->x + 1;
}

bool	can_move(t_player *player, t_map *map, int input)
{
	if ((input == 87 || input == 119) &&
		(map->grid[player->y - 1][player->x] == '1'))
	{
		return (false);
	}
	else if ((input == 115 || input == 83) &&
				(map->grid[player->y + 1][player->x] == '1'))
	{
		return (false);
	}
	else if ((input == 97 || input == 65) &&
				(map->grid[player->y][player->x - 1] == '1'))
	{
		return (false);
	}
	else if ((input == 100 || input == 68) &&
				(map->grid[player->y][player->x + 1] == '1'))
	{
		return (false);
	}
	return (true);
}
