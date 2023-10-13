/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:47:24 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 04:39:45 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player.prev_x;
	prev_y = game->player.prev_y;
	game->texture.img_player->instances[0].x = new_x;
	game->texture.img_player->instances[0].y = new_y;
	show_move_count(game);
	if (game->map.grid[new_y][new_x] == 'C')
		delete_c_img(game);
	win_or_lose(game, new_x, new_y);
	game->map.grid[prev_y][prev_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		real_pos_x;
	int		real_pos_y;
	int		map_pos_x;
	int		map_pos_y;

	game = param;
	real_pos_x = game->texture.img_player->instances[0].x;
	real_pos_y = game->texture.img_player->instances[0].y;
	map_pos_x = real_pos_x / SIZE_IMG;
	map_pos_y = real_pos_y / SIZE_IMG;
	game->player.prev_x = map_pos_x;
	game->player.prev_y = map_pos_y;
	if (keydata.key == 256 && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (game->g_stop_action == true)
		return ;
	if (keydata.key == 87 || keydata.key == 265)
	{
		if (keydata.action == MLX_PRESS && game->map.grid
			[map_pos_y - 1][map_pos_x] != '1')
			move_player(game, map_pos_x, map_pos_y - 1);
	}
	else if (keydata.key == 264 || keydata.key == 83)
	{
		if (keydata.action == MLX_PRESS && game->map.grid
			[map_pos_y + 1][map_pos_x] != '1')
			move_player(game, map_pos_x, map_pos_y + 1);
	}
	else if (keydata.key == 263 || keydata.key == 65)
	{
		if (keydata.action == MLX_PRESS && game->map.grid[map_pos_y][map_pos_x
			- 1] != '1')
			move_player(game, map_pos_x - 1, map_pos_y);
	}
	else if (keydata.key == 262 || keydata.key == 68)
	{
		if (keydata.action == MLX_PRESS && game->map.grid[map_pos_y][map_pos_x
			+ 1] != '1')
			move_player(game, map_pos_x + 1, map_pos_y);
	}
}

void	show_move_count(t_game *game)
{
	char	*moves_count;

	system("clear");
	if (game->texture.g_img_p_move)
		mlx_delete_image(game->mlx, game->texture.g_img_p_move);
	game->player.count_move += 1;
	moves_count = ft_itoa(game->player.count_move);
	printf(" \n   your current moves are  %i moves \n",
			game->player.count_move);
	game->texture.g_img_p_move = mlx_put_string(game->mlx, moves_count, SIZE_IMG
			* 5, (game->map.height * SIZE_IMG) + 50);
	free(moves_count);
	moves_count = NULL;
}

int	errror(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(-1);
}
