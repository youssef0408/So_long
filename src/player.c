/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:08:40 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/02 16:00:45 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	init_player(t_player *player, t_map map)
// {
// 	player->x = map.p_x;
// 	player->y = map.p_y;
// 	player->count_c = 0;
// 	player->prev_x = -1;
// 	player->prev_y = -1;
// }

void	init_player(t_player *player, int x, int y)
{
	player->x = x;
	player->y = y;
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

void	move_auto(t_player *enemy, t_map *map, int input)
{
	bool	has_moved;

	has_moved = false;
	enemy->prev_x = enemy->x;
	enemy->prev_y = enemy->y;
	input = 1;
	printf("unput   %i\n", input);
	printf(" 0 up pos   %c\n", map->grid[enemy->y - 1][enemy->x]);
	printf(" 1 down pos   %c\n", map->grid[enemy->y + 1][enemy->x]);
	printf(" 2 left pos   %c\n", map->grid[enemy->y][enemy->x - 1]);
	printf(" 3 right pos  %c\n", map->grid[enemy->y][enemy->x + 1]);
	if (input == 0 && map->grid[enemy->y - 1][enemy->x] != '1'
		&& map->grid[enemy->y - 1][enemy->x] != 'C' && map->grid[enemy->y
		- 1][enemy->x] != 'E')
	{
		move_up(enemy);
		has_moved = true;
	}
	else if (input == 1 && map->grid[enemy->y + 1][enemy->x] != '1'
			&& map->grid[enemy->y + 1][enemy->x] == 'C' &&
				map->grid[enemy->y + 1][enemy->x] != 'E')
	{
		move_down(enemy);
		has_moved = true;
	}
	else if (input == 2 && map->grid[enemy->y][enemy->x - 1] != '1'
			&& map->grid[enemy->y][enemy->x - 1] != 'C' &&
				map->grid[enemy->y][enemy->x - 1] != 'E')
	{
		move_left(enemy);
		has_moved = true;
	}
	else if (input == 3 && map->grid[enemy->y][enemy->x + 1] != '1'
			&& map->grid[enemy->y][enemy->x + 1] != 'C'
			&& map->grid[enemy->y][enemy->x + 1] != 'E')
	{
		move_right(enemy);
		has_moved = true;
	}
	if (has_moved)
	{
		map->grid[enemy->prev_y][enemy->prev_x] = '0';
		map->grid[enemy->y][enemy->x] = '*';
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
	if (input < 0)
	{
		perror("Error Invalid direction \n");
		return (false);
	}
	else if ((input == 87 || input == 119) && (map->grid[player->y
				- 1][player->x] == '1'))
	{
		return (false);
	}
	else if ((input == 115 || input == 83) && (map->grid[player->y
				+ 1][player->x] == '1'))
	{
		return (false);
	}
	else if ((input == 97 || input == 65) && (map->grid[player->y][player->x
				- 1] == '1'))
	{
		return (false);
	}
	else if ((input == 100 || input == 68) && (map->grid[player->y][player->x
				+ 1] == '1'))
	{
		return (false);
	}
	else if (can_exit(player, map, input) == false)
		return (false);
	return (true);
}

bool	can_exit(t_player *player, t_map *map, int input)
{
	if ((input == 87 || input == 119) && (map->grid[player->y
			- 1][player->x] == 'E'))
	{
		if (player->count_c < map->count_c)
		{
			perror("you can't exit the game without all the colectables!\n");
			return (false);
		}
		return (true);
	}
	else if ((input == 115 || input == 83) && (map->grid[player->y
				+ 1][player->x] == 'E'))
	{
		if (player->count_c < map->count_c)
		{
			perror("you can't exit the game without all the colectables!\n");
			return (false);
		}
		return (true);
	}
	else if ((input == 97 || input == 65) && (map->grid[player->y][player->x
				- 1] == 'E'))
	{
		if (player->count_c < map->count_c)
		{
			perror("you can't exit the game without all the colectables!\n");
			return (false);
		}
		return (true);
	}
	else if ((input == 100 || input == 68) && (map->grid[player->y][player->x
				+ 1] == 'E'))
	{
		if (player->count_c < map->count_c)
		{
			perror("you can't exit the game without all the colectables!\n");
			return (false);
		}
		return (true);
	}
	return (true);
}
