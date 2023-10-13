/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:54:18 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 17:05:27 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	enemy_moves_up(int input, t_game *game, int map_positions[4])
{
	if (input == 0 && game->map.grid[map_positions[MAP_POS_Y]
			- 1][map_positions[MAP_POS_X]] != '1'
		&& game->map.grid[map_positions[MAP_POS_Y]
		- 1][map_positions[MAP_POS_X]] != 'C'
		&& game->map.grid[map_positions[MAP_POS_Y]
		- 1][map_positions[MAP_POS_X]] != 'E')
	{
		update_img_pos(game, map_positions[REAL_POS_X],
			map_positions[REAL_POS_Y] - SIZE_IMG);
		kill_player(game, map_positions[MAP_POS_X], map_positions[MAP_POS_Y]
			- 1);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_positions[MAP_POS_Y]
			- 1][map_positions[MAP_POS_X]] = 'M';
	}
}

void	enemy_moves_down(int input, t_game *game, int map_positions[4])
{
	if (input == 1 && game->map.grid[map_positions[MAP_POS_Y]
			+ 1][map_positions[MAP_POS_X]] != '1'
		&& game->map.grid[map_positions[MAP_POS_Y]
		+ 1][map_positions[MAP_POS_X]] != 'C'
		&& game->map.grid[map_positions[MAP_POS_Y]
		+ 1][map_positions[MAP_POS_X]] != 'E')
	{
		update_img_pos(game, map_positions[REAL_POS_X],
			map_positions[REAL_POS_Y] + SIZE_IMG);
		kill_player(game, map_positions[MAP_POS_X], map_positions[MAP_POS_Y]
			+ 1);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_positions[MAP_POS_Y]
			+ 1][map_positions[MAP_POS_X]] = 'M';
	}
}

void	enemy_moves_left(int input, t_game *game, int map_positions[4])
{
	if (input == 2
		&& game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
		- 1] != '1'
		&& game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
		- 1] != 'C'
		&& game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
		- 1] != 'E')
	{
		update_img_pos(game, map_positions[REAL_POS_X] - SIZE_IMG,
			map_positions[REAL_POS_Y]);
		kill_player(game, map_positions[MAP_POS_X] - 1,
			map_positions[MAP_POS_Y]);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
			- 1] = 'M';
	}
}

void	enemy_moves_right(int input, t_game *game, int map_positions[4])
{
	if (input == 3
		&& game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
		+ 1] != '1'
		&& game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
		+ 1] != 'C'
		&& game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
		+ 1] != 'E')
	{
		update_img_pos(game, map_positions[REAL_POS_X] + SIZE_IMG,
			map_positions[REAL_POS_Y]);
		kill_player(game, map_positions[MAP_POS_X] + 1,
			map_positions[MAP_POS_Y]);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_positions[MAP_POS_Y]][map_positions[MAP_POS_X]
			+ 1] = 'M';
	}
}

void	enemy_moves(void *param)
{
	int		map_positions[4];
	int		input;
	t_game	*game;

	game = param;
	if (!game->map.has_m)
		return ;
	game->g_timer += 1;
	if (game->g_timer < 25)
		return ;
	game->g_timer = 0;
	input = rand() % 4;
	toggle_img(game);
	map_positions[REAL_POS_X] = game->texture.img_ennemy->instances[0].x;
	map_positions[REAL_POS_Y] = game->texture.img_ennemy->instances[0].y;
	map_positions[MAP_POS_X] = map_positions[REAL_POS_X] / SIZE_IMG;
	map_positions[MAP_POS_Y] = map_positions[REAL_POS_Y] / SIZE_IMG;
	game->enemy.prev_x = map_positions[MAP_POS_X];
	game->enemy.prev_y = map_positions[MAP_POS_Y];
	if (game->g_stop_action == true)
		return ;
	enemy_moves_up(input, game, map_positions);
	enemy_moves_down(input, game, map_positions);
	enemy_moves_left(input, game, map_positions);
	enemy_moves_right(input, game, map_positions);
}
