/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/04 21:26:21 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 1257
//1*1000 = 2
mlx_image_t	*img_p_move = NULL;
mlx_image_t	*img_nb_coll = NULL;
mlx_image_t	*img_win = NULL;

static void	error(void)
{
	//puts(mlx_strerror(mlx_errno));
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
	mlx_resize_image(game->texture.img_player, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_wall, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_floor, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_collectables, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_exit, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->texture.img_ennemy, SIZE_IMG, SIZE_IMG);
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
	// puts("DIEGO");
	if (mlx_image_to_window(game->mlx, game->texture.img_player, game->map.p_x
			* SIZE_IMG, game->map.p_y * SIZE_IMG) < 0)
		error();
	if (mlx_image_to_window(game->mlx, game->texture.img_exit, game->map.e_x
			* SIZE_IMG, game->map.e_y * SIZE_IMG) < 0)
		error();
	if (mlx_image_to_window(game->mlx, game->texture.img_ennemy, game->map.m_x
			* SIZE_IMG, game->map.m_y * SIZE_IMG) < 0)
		error();
}

void	play_game(t_game *game)
{
	// char	*str2;
	// char	*output;
	// output = "Collectables ";
	// str2 = ft_itoa(game->map.count_c);
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

char	**ft_create_render_map(t_map *map, int fd)
{
	char	**table;
	char	*str;
	int		i;

	table = ft_calloc(sizeof(char *), (map->height + 1)); //height
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
	if ((keydata.key == 87 || keydata.key == 119) && keydata.action == MLX_PRESS
		&& (game->map.grid[map_pos_y - 1][map_pos_x] != '1'))
	{
		game->texture.img_player->instances[0].y -= SIZE_IMG;
		show_move(game);
		if (game->map.grid[map_pos_y - 1][map_pos_x] == 'C')
		{
			delete_c_img(game);
		}
		win_condition(game, map_pos_x, map_pos_y - 1);
	}
	else if ((keydata.key == 115 || keydata.key == 83)
			&& keydata.action == MLX_PRESS && (game->map.grid[map_pos_y
				+ 1][map_pos_x] != '1'))
	{
		game->texture.img_player->instances[0].y += SIZE_IMG;
		show_move(game);
		if (game->map.grid[map_pos_y + 1][map_pos_x] == 'C')
		{
			delete_c_img(game);
		}
		win_condition(game, map_pos_x, map_pos_y + 1);
	}
	else if ((keydata.key == 97 || keydata.key == 65)
			&& keydata.action == MLX_PRESS
			&& (game->map.grid[map_pos_y][map_pos_x - 1] != '1'))
	{
		game->texture.img_player->instances[0].x -= SIZE_IMG;
		show_move(game);
		if (game->map.grid[map_pos_y][map_pos_x - 1] == 'C')
		{
			delete_c_img(game);
		}
		win_condition(game, map_pos_x - 1, map_pos_y);
	}
	else if ((keydata.key == 100 || keydata.key == 68)
			&& keydata.action == MLX_PRESS
			&& (game->map.grid[map_pos_y][map_pos_x + 1] != '1'))
	{
		game->texture.img_player->instances[0].x += SIZE_IMG;
		show_move(game);
		if (game->map.grid[map_pos_y][map_pos_x + 1] == 'C')
		{
			delete_c_img(game);
		}
		win_condition(game, map_pos_x + 1, map_pos_y);
	}
}
void	show_move(t_game *game)
{
	if (img_p_move)
	{
		mlx_delete_image(game->mlx, img_p_move);
	}
	game->player.count_move += 1;
	img_p_move = mlx_put_string(game->mlx, ft_itoa(game->player.count_move),
			SIZE_IMG * 5, (game->map.height * SIZE_IMG) + 50);
}

void	show_nb_col(t_game *game)
{
	if (img_nb_coll)
	{
		mlx_delete_image(game->mlx, img_nb_coll);
	}
	// game->player.count_c += 1;
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
	show_nb_col(game);
}

void	win_condition(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'E'
		&& game->map.count_c == game->player.count_c)
	{
		puts("U WON!");
	}
}