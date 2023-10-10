/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:35:48 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/10 02:13:42 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (game->map.grid[y][x] == 'E'
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

void	play_game(t_game *game)
{
	char	*nbm;
	char	*nbc;
	char	*max_c;

	game->g_timer = 0;
	game->g_stop_action = false;
	ft_render_window(game);
	mlx_put_string(game->mlx, "Collectables:", SIZE_IMG, (game->map.height
			* SIZE_IMG) + 25);
	nbc = ft_itoa(game->player.count_c);
	game->texture.g_img_nb_coll = mlx_put_string(game->mlx, nbc, SIZE_IMG * 5,
			(game->map.height * SIZE_IMG) + 25);
	free(nbc);
	nbc = NULL;
	mlx_put_string(game->mlx, "/", SIZE_IMG * 5 + 13, (game->map.height
			* SIZE_IMG) + 25);
	max_c = ft_itoa(game->map.count_c);
	mlx_put_string(game->mlx, max_c, SIZE_IMG * 5 + 20, (game->map.height
			* SIZE_IMG) + 25);
	free(max_c);
	max_c = NULL;
	mlx_put_string(game->mlx, "Moves:", SIZE_IMG, (game->map.height * SIZE_IMG)
		+ 50);
	nbm = ft_itoa(game->player.count_move);
	game->texture.g_img_p_move = mlx_put_string(game->mlx, nbm, SIZE_IMG * 5,
			(game->map.height * SIZE_IMG) + 50);
	free(nbm);
	nbm = NULL;
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, enemy_moves, game);
	mlx_loop(game->mlx);
	free(game->texture.g_img_win);
	free(game->texture.g_img_p_move);
	free(game->texture.g_img_nb_coll);
	mlx_terminate(game->mlx);
}

int	show_command(void)
{
	char	c;
	int		command;

	printf("W / ⬆   - UP \n");
	printf("S / ⬇   - DOWN \n");
	printf("A / ◀️   - LEFT \n");
	printf("D / ▶️   - RIGHT \n");
	printf("Esc     - Exit \n");
	printf("choose a direction : \n");
	scanf("%c", &c);
	command = c;
	if (command != 'w' && command != 'W' && command != 'A' && command != 'a'
		&& command != 's' && command != 'S' && command != 'D' && command != 'd'
		&& command != 27 && command != 113 && command != 10)
	{
		printf("Invalid direction! \n");
		return (-2);
	}
	return (command);
}
