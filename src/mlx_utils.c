/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/07 16:06:48 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t		*img_p_move = NULL;
mlx_image_t		*img_nb_coll = NULL;
mlx_image_t		*img_win = NULL;
long long int	timer;
bool			stop_action;

static void	error(void)
{
	// puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_create_texture(t_game *game)
{
	game->texture.texture_player = mlx_load_png("./includes/textures/player.png");
	game->texture.texture_wall = mlx_load_png("./includes/textures/wall.png");
	game->texture.texture_floor = mlx_load_png("./includes/textures/floor.png");
	game->texture.texture_collectables = mlx_load_png("./includes/textures/collectables.png");
	game->texture.texture_exit = mlx_load_png("./includes/textures/sortie.png");
	game->texture.texture_ennemy = mlx_load_png("./includes/textures/enemy.png");
	game->texture.texture_win = mlx_load_png("./includes/textures/winner.png");
	game->texture.texture_loser = mlx_load_png("./includes/textures/loser.png");
	if (!game->texture.texture_win)
		error();
	if (!game->texture.texture_loser)
		error();
	if (!game->texture.texture_player)
		error();
	if (!game->texture.texture_wall)
		error();
	if (!game->texture.texture_floor)
		error();
	if (!game->texture.texture_collectables)
		error();
	if (!game->texture.texture_exit)
		error();
	if (!game->texture.texture_ennemy)
		error();
	game->texture.img_player = mlx_texture_to_image(game->mlx,
													game->texture.texture_player);
	game->texture.img_wall = mlx_texture_to_image(game->mlx,
													game->texture.texture_wall);
	game->texture.img_floor = mlx_texture_to_image(game->mlx,
													game->texture.texture_floor);
	game->texture.img_collectables = mlx_texture_to_image(game->mlx,
															game->texture.texture_collectables);
	game->texture.img_exit = mlx_texture_to_image(game->mlx,
													game->texture.texture_exit);
	game->texture.img_ennemy = mlx_texture_to_image(game->mlx,
													game->texture.texture_ennemy);
	game->texture.img_win = mlx_texture_to_image(game->mlx,
													game->texture.texture_win);
	game->texture.img_loser = mlx_texture_to_image(game->mlx,
													game->texture.texture_loser);
	mlx_resize_image(game->texture.img_player, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_wall, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_floor, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_collectables, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_exit, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_ennemy, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_win, SIZE_IMG * game->map.width,
			game->map.height * SIZE_IMG + 100);
	mlx_resize_image(game->texture.img_loser, SIZE_IMG * game->map.width,
			game->map.height * SIZE_IMG + 100);
}

void	ft_render_window(t_game *game)
{
	size_t	x;
	size_t	y;

	if (!(game->mlx = mlx_init((game->map.width) * SIZE_IMG, (game->map.height
					* SIZE_IMG) + 100, "so_long", false)))
	{
		puts(mlx_strerror(10));
		return ;
	}
	ft_create_texture(game);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			ft_render_texture_img(game, x, y);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(game->mlx, game->texture.img_exit, game->map.e_x
			* SIZE_IMG, game->map.e_y * SIZE_IMG) < 0)
		error();
	if (mlx_image_to_window(game->mlx, game->texture.img_player, game->map.p_x
			* SIZE_IMG, game->map.p_y * SIZE_IMG) < 0)
		error();
	if (mlx_image_to_window(game->mlx, game->texture.img_ennemy, game->map.m_x
			* SIZE_IMG, game->map.m_y * SIZE_IMG) < 0)
		error();
}

void	play_game(t_game *game)
{
	timer = 0;
	stop_action = false;
	ft_render_window(game);
	mlx_put_string(game->mlx, "Collectables:", SIZE_IMG, (game->map.height
				* SIZE_IMG) + 25);
	img_nb_coll = mlx_put_string(game->mlx, ft_itoa(game->player.count_c),
			SIZE_IMG * 5, (game->map.height * SIZE_IMG) + 25);
	mlx_put_string(game->mlx, "/", SIZE_IMG * 5 + 10, (game->map.height
				* SIZE_IMG) + 25);
	mlx_put_string(game->mlx, ft_itoa(game->map.count_c), SIZE_IMG * 5 + 20,
			(game->map.height * SIZE_IMG) + 25);
	mlx_put_string(game->mlx, "Moves:", SIZE_IMG, (game->map.height * SIZE_IMG)
			+ 50);
	img_p_move = mlx_put_string(game->mlx, ft_itoa(game->player.count_move),
			SIZE_IMG * 5, (game->map.height * SIZE_IMG) + 50);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, enemy_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	ft_render_texture_img(t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx, game->texture.img_floor, x * SIZE_IMG, y
			* SIZE_IMG) < 0)
		error();
	if (game->map.grid[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->texture.img_wall, x * SIZE_IMG,
				y * SIZE_IMG) < 0)
			error();
	}
	else if (game->map.grid[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->texture.img_collectables, x
				* SIZE_IMG, y * SIZE_IMG) < 0)
			error();
	}
}

char	**ft_create_render_map(t_game *game, int fd)
{
	char	**table;
	char	*str;
	int		i;

	table = ft_calloc(sizeof(char *), (game->map->height + 1));
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		table[i] = str;
		str = get_next_line(fd);
		i++;
	}
	return (table);
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
	 if ((keydata.key == 256) && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (stop_action == true)
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
	if (img_p_move)
	{
		mlx_delete_image(game->mlx, img_p_move);
	}
	game->player.count_move += 1;
	img_p_move = mlx_put_string(game->mlx, ft_itoa(game->player.count_move),
			SIZE_IMG * 5, (game->map.height * SIZE_IMG) + 50);
}

void	show_items_count(t_game *game)
{
	if (img_nb_coll)
	{
		mlx_delete_image(game->mlx, img_nb_coll);
	}
	img_nb_coll = mlx_put_string(game->mlx, ft_itoa(game->player.count_c),
			SIZE_IMG * 5, (game->map.height * SIZE_IMG) + 25);
}

void	delete_c_img(t_game *game)
{
	int	i;
	int	final_count;
	int	p_x;
	int	p_y;

	p_x = game->texture.img_player->instances[0].x;
	p_y = game->texture.img_player->instances[0].y;
	final_count = game->map.count_c;
	i = 0;
	while (i <= final_count)
	{
		if (p_x == game->texture.img_collectables->instances[i].x
			&& p_y == game->texture.img_collectables->instances[i].y)
		{
			game->texture.img_collectables->instances[i]
				.enabled = false;
			game->map.grid[p_y / SIZE_IMG][p_x / SIZE_IMG] = '0';
			game->player.count_c += 1;
			break ;
		}
		i++;
	}
	show_items_count(game);
}

void	win_or_lose(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'E'
		&& game->map.count_c == game->player.count_c)
	{
		puts("U WON!");
		if (mlx_image_to_window(game->mlx, game->texture.img_win, 0, 0) < 0)
			error();
		stop_action = true;
		// mlx_close_window(game->mlx);
		// sleep(3);
	}
	if (game->map.grid[y][x] == 'M')
	{
		puts("U LOST!");
		if (mlx_image_to_window(game->mlx, game->texture.img_loser, 0, 0) < 0)
			error();
		stop_action = true;
		// sleep(3);
		// mlx_close_window(game->mlx);
	}
}

// void	*enemy_moves(t_game *game)
void	enemy_moves(void *param)
{
	int		real_pos_x;
	int		real_pos_y;
	int		map_pos_x;
	int		map_pos_y;
	int		input;
	t_game	*game;

	timer += 1;
	if (timer < 30)
		return ;
	timer = 0;
	game = param;
	input = rand() % 4;
	real_pos_x = game->texture.img_ennemy->instances[0].x;
	real_pos_y = game->texture.img_ennemy->instances[0].y;
	map_pos_x = real_pos_x / SIZE_IMG;
	map_pos_y = real_pos_y / SIZE_IMG;
	game->enemy.prev_x = map_pos_x;
	game->enemy.prev_y = map_pos_y;
	if (stop_action == true)
		return ;
	if (input == 0 && game->map.grid[map_pos_y - 1][map_pos_x] != '1'
		&& game->map.grid[map_pos_y - 1][map_pos_x] != 'C'
		&& game->map.grid[map_pos_y - 1][map_pos_x] != 'E')
	{
		game->texture.img_ennemy->instances[0].y -= SIZE_IMG;
		kill_player(game, map_pos_x, map_pos_y - 1);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y - 1][map_pos_x] = 'M';
		// has_moved = true;
	}
	else if (input == 1 && game->map.grid[map_pos_y + 1][map_pos_x] != '1'
			&& game->map.grid[map_pos_y + 1][map_pos_x] != 'C'
			&& game->map.grid[map_pos_y + 1][map_pos_x] != 'E')
	{
		game->texture.img_ennemy->instances[0].y += SIZE_IMG;
		kill_player(game, map_pos_x, map_pos_y + 1);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y + 1][map_pos_x] = 'M';
		// has_moved = true;
	}
	else if (input == 2 && game->map.grid[map_pos_y][map_pos_x - 1] != '1'
			&& game->map.grid[map_pos_y][map_pos_x - 1] != 'C'
			&& game->map.grid[map_pos_y][map_pos_x - 1] != 'E')
	{
		game->texture.img_ennemy->instances[0].x -= SIZE_IMG;
		kill_player(game, map_pos_x - 1, map_pos_y);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y][map_pos_x - 1] = 'M';
		// has_moved = true;
	}
	else if (input == 3 && game->map.grid[map_pos_y][map_pos_x + 1] != '1'
			&& game->map.grid[map_pos_y][map_pos_x + 1] != 'C'
			&& game->map.grid[map_pos_y][map_pos_x + 1] != 'E')
	{
		game->texture.img_ennemy->instances[0].x += SIZE_IMG;
		kill_player(game, map_pos_x + 1, map_pos_y);
		game->map.grid[game->enemy.prev_y][game->enemy.prev_x] = '0';
		game->map.grid[map_pos_y][map_pos_x + 1] = 'M';
		// has_moved = true;
	}
}

void	kill_player(t_game *game, int x, int y)
{
	// show_grid(&game->map);
	if (game->map.grid[y][x] == 'P')
	{
		puts("U LOST!");
		if (mlx_image_to_window(game->mlx, game->texture.img_loser, 0, 0) < 0)
			error();
		stop_action = true;
	}
}