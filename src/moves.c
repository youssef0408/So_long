/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:47:24 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/10 00:48:35 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if ((keydata.key == 256) && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (game->g_stop_action == true)
		return ;
	if ((keydata.key == 87 || keydata.key == 265) && keydata.action == MLX_PRESS
		&& (game->map.grid[map_pos_y - 1][map_pos_x] != '1'))
	{
		game->texture.img_player->instances[0].y -= SIZE_IMG;
		// enemy_moves(game, enemy_input);
		show_move_count(game);
		// show_grid(&game->map);
		if (game->map.grid[map_pos_y - 1][map_pos_x] == 'C')
			delete_c_img(game);
		win_or_lose(game, map_pos_x, map_pos_y - 1);
		game->map.grid[game->player.prev_y][game->player.prev_x] = '0';
		game->map.grid[map_pos_y - 1][map_pos_x] = 'P';
	}
	else if ((keydata.key == 264 || keydata.key == 83)
			&& keydata.action == MLX_PRESS && (game->map.grid[map_pos_y
				+ 1][map_pos_x] != '1'))
	{
		game->texture.img_player->instances[0].y += SIZE_IMG;
		// enemy_moves(game, enemy_input);
		show_move_count(game);
		// show_grid(&game->map);
		if (game->map.grid[map_pos_y + 1][map_pos_x] == 'C')
			delete_c_img(game);
		win_or_lose(game, map_pos_x, map_pos_y + 1);
		game->map.grid[game->player.prev_y][game->player.prev_x] = '0';
		game->map.grid[map_pos_y + 1][map_pos_x] = 'P';
	}
	else if ((keydata.key == 263 || keydata.key == 65)
			&& keydata.action == MLX_PRESS
			&& (game->map.grid[map_pos_y][map_pos_x - 1] != '1'))
	{
		game->texture.img_player->instances[0].x -= SIZE_IMG;
		// enemy_moves(game, enemy_input);
		show_move_count(game);
		// show_grid(&game->map);
		if (game->map.grid[map_pos_y][map_pos_x - 1] == 'C')
			delete_c_img(game);
		win_or_lose(game, map_pos_x - 1, map_pos_y);
		game->map.grid[game->player.prev_y][game->player.prev_x] = '0';
		game->map.grid[map_pos_y][map_pos_x - 1] = 'P';
	}
	else if ((keydata.key == 262 || keydata.key == 68)
			&& keydata.action == MLX_PRESS
			&& (game->map.grid[map_pos_y][map_pos_x + 1] != '1'))
	{
		game->texture.img_player->instances[0].x += SIZE_IMG;
		// enemy_moves(game, enemy_input);
		show_move_count(game);
		// show_grid(&game->map);
		if (game->map.grid[map_pos_y][map_pos_x + 1] == 'C')
			delete_c_img(game);
		win_or_lose(game, map_pos_x + 1, map_pos_y);
		game->map.grid[game->player.prev_y][game->player.prev_x] = '0';
		game->map.grid[map_pos_y][map_pos_x + 1] = 'P';
	}
}

void	show_move_count(t_game *game)
{
	char *nbm;

	if (game->texture.g_img_p_move)
	{
		mlx_delete_image(game->mlx, game->texture.g_img_p_move);
	}
	game->player.count_move += 1;
	nbm = ft_itoa(game->player.count_move);
	game->texture.g_img_p_move = mlx_put_string(game->mlx, nbm, SIZE_IMG * 5,
			(game->map.height * SIZE_IMG) + 50);
	// free(img_p_move);
	free(nbm);
	nbm = NULL;
}
