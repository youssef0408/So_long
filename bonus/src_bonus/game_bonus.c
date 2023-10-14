/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:35:48 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 22:11:06 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

bool	init_game(char *file_name, t_map *map)
{
	int	fd;

	fd = open_file(file_name);
	if (fd < 0)
	{
		close(fd);
		perror("Error openning file \n");
		return (false);
	}
	if (!parse_file(map, fd))
	{
		close(fd);
		perror("Error Parsing file \n");
		return (false);
	}
	return (true);
}

void	win_or_lose(t_game *game, size_t x, size_t y)
{
	if (game->map.e_x == x && game->map.e_y == y
		&& game->map.count_c == game->player.count_c)
	{
		puts("U WON!");
		if (mlx_image_to_window(game->mlx, game->texture.img_win, 0, 0) < 0)
			errror();
		game->g_stop_action = true;
	}
	if (game->map.grid[y][x] == 'M')
	{
		puts("U LOST!");
		if (mlx_image_to_window(game->mlx, game->texture.img_loser, 0, 0) < 0)
			errror();
		game->g_stop_action = true;
	}
}

void	display_collectables_and_moves(t_game *game)
{
	char	*items_collected;
	char	*total_items;
	char	*moves_count;

	game->texture.g_img_coll_str = mlx_put_string(game->mlx, "Collectables:",
			SIZE_IMG, (game->map.height * SIZE_IMG) + 25);
	items_collected = ft_itoa(game->player.count_c);
	game->texture.g_img_nb_coll = mlx_put_string(game->mlx, items_collected,
			SIZE_IMG * 5, (game->map.height * SIZE_IMG) + 25);
	free(items_collected);
	items_collected = NULL;
	game->texture.g_img_slash_str = mlx_put_string(game->mlx, "/", SIZE_IMG * 5
			+ 20, (game->map.height * SIZE_IMG) + 25);
	total_items = ft_itoa(game->map.count_c);
	game->texture.g_img_total_str = mlx_put_string(game->mlx, total_items,
			SIZE_IMG * 5 + 30, (game->map.height * SIZE_IMG) + 25);
	free(total_items);
	total_items = NULL;
	game->texture.g_img_move_str = mlx_put_string(game->mlx, "Moves:", SIZE_IMG,
			(game->map.height * SIZE_IMG) + 50);
	moves_count = ft_itoa(game->player.count_move);
	game->texture.g_img_p_move = mlx_put_string(game->mlx, moves_count, SIZE_IMG
			* 5, (game->map.height * SIZE_IMG) + 50);
	free(moves_count);
	moves_count = NULL;
}

void	toggle_exite(void *param)
{
	t_game	*game;

	game = param;
	if (game->player.count_c == game->map.count_c)
	{
		game->texture.img_exit_close->enabled = false;
		game->texture.img_exit_open->enabled = true;
	}
}

void	play_game(t_game *game)
{
	game->g_timer = 0;
	game->g_stop_action = false;
	ft_render_window(game);
	mlx_put_string(game->mlx, "Collectables:", SIZE_IMG, (game->map.height
			* SIZE_IMG) + 25);
	display_collectables_and_moves(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, enemy_moves, game);
	mlx_loop_hook(game->mlx, toggle_exite, game);
	mlx_loop(game->mlx);
	clean_images(*game);
	clean_texture(*game);
	mlx_terminate(game->mlx);
}
