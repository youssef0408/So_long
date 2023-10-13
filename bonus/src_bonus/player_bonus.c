/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:32:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/12 20:41:13 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player(t_player *player, int x, int y)
{
	if (x == -1 && y == -1)
		return ;
	player->x = x;
	player->y = y;
	player->count_c = 0;
	player->prev_x = -1;
	player->prev_y = -1;
	player->count_move = 0;
}

void	toggle_img(t_game *game)
{
	game->texture.img_ennemy->enabled = !game->texture.img_ennemy->enabled;
	game->texture.img_ennemy2->enabled = !game->texture.img_ennemy->enabled;
}

void	update_img_pos(t_game *game, size_t x, size_t y)
{
	game->texture.img_ennemy->instances[0].x = x;
	game->texture.img_ennemy->instances[0].y = y;
	game->texture.img_ennemy2->instances[0].x = x;
	game->texture.img_ennemy2->instances[0].y = y;
}

void	enemy_moves(void *param)
{
	int		real_pos_x;
	int		real_pos_y;
	int		map_pos_x;
	int		map_pos_y;
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
	real_pos_x = game->texture.img_ennemy->instances[0].x;
	real_pos_y = game->texture.img_ennemy->instances[0].y;
	map_pos_x = real_pos_x / SIZE_IMG;
	map_pos_y = real_pos_y / SIZE_IMG;
	game->enemy.prev_x = map_pos_x;
	game->enemy.prev_y = map_pos_y;
	if (game->g_stop_action == true)
		return ;
	if (input == 0 && game->map.grid[map_pos_y - 1][map_pos_x] != '1'
		&& game->map.grid[map_pos_y - 1][map_pos_x] != 'C'
		&& game->map.grid[map_pos_y - 1][map_pos_x] != 'E')
	{
		update_img_pos(game, real_pos_x, real_pos_y - SIZE_IMG);
		kill_player(game, map_pos_x, map_pos_y - 1);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y - 1][map_pos_x] = 'M';
	}
	else if (input == 1 && game->map.grid[map_pos_y + 1][map_pos_x] != '1'
			&& game->map.grid[map_pos_y + 1][map_pos_x] != 'C'
			&& game->map.grid[map_pos_y + 1][map_pos_x] != 'E')
	{
		update_img_pos(game, real_pos_x, real_pos_y + SIZE_IMG);
		kill_player(game, map_pos_x, map_pos_y + 1);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y + 1][map_pos_x] = 'M';
	}
	else if (input == 2 && game->map.grid[map_pos_y][map_pos_x - 1] != '1'
			&& game->map.grid[map_pos_y][map_pos_x - 1] != 'C'
			&& game->map.grid[map_pos_y][map_pos_x - 1] != 'E')
	{
		update_img_pos(game, real_pos_x - SIZE_IMG, real_pos_y);
		kill_player(game, map_pos_x - 1, map_pos_y);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y][map_pos_x - 1] = 'M';
	}
	else if (input == 3 && game->map.grid[map_pos_y][map_pos_x + 1] != '1'
			&& game->map.grid[map_pos_y][map_pos_x + 1] != 'C'
			&& game->map.grid[map_pos_y][map_pos_x + 1] != 'E')
	{
		update_img_pos(game, real_pos_x + SIZE_IMG, real_pos_y);
		kill_player(game, map_pos_x + 1, map_pos_y);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y][map_pos_x + 1] = 'M';
	}
}

void	kill_player(t_game *game, size_t x, size_t y)
{
	if (game->map.grid[y][x] == 'P')
	{
		puts("U LOST!");
		if (mlx_image_to_window(game->mlx, game->texture.img_loser, 0, 0) < 0)
			errror();
		game->g_stop_action = true;
	}
}
