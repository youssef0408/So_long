/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:32:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 17:10:51 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

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

void	update_img_pos(t_game *game, size_t x, size_t y)
{
	game->texture.img_ennemy->instances[0].x = x;
	game->texture.img_ennemy->instances[0].y = y;
	game->texture.img_ennemy2->instances[0].x = x;
	game->texture.img_ennemy2->instances[0].y = y;
}
