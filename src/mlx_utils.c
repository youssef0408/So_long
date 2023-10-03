/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/03 12:28:05 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_create_texture(t_textures *texture)
{
	texture->texture_player = mlx_load_png("includes/textures/chuki.png");
	texture->texture_wall = mlx_load_png("includes/textures/wall.png");
	texture->texture_field = mlx_load_png("includes/textures/field.png");
	texture->texture_ball = mlx_load_png("includes/textures/ball.png");
	texture->texture_exit = mlx_load_png("includes/textures/Exit.png");
	if (!texture->texture_player)
		error();
	if (!texture->texture_wall)
		error();
	if (!texture->texture_field)
		error();
	if (!texture->texture_ball)
		error();
	if (!texture->texture_exit)
		error();
	texture->img_player = mlx_texture_to_image(texture->mlx, texture->texture_player);
	texture->img_wall = mlx_texture_to_image(texture->mlx, texture->texture_wall);
	texture->img_field = mlx_texture_to_image(texture->mlx, texture->texture_field);
	texture->img_ball = mlx_texture_to_image(texture->mlx, texture->texture_ball);
	texture->img_exit = mlx_texture_to_image(texture->mlx, texture->texture_exit);
	mlx_resize_image(texture->img_player, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(texture->img_wall, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(texture->img_field, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(texture->img_ball, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(texture->img_exit, SIZE_IMG, SIZE_IMG);
}

void	ft_render_winwow(t_map *map)
{
	size_t		x;
	size_t		y;
	t_textures	texture;

	if (!(texture.mlx = mlx_init((map->width) * SIZE_IMG,
		map->height * SIZE_IMG, "so_long", false)))
	{
		puts(mlx_strerror(10));
		return ;
	}
	ft_create_texture(&texture);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_render_texture_img(map, &texture, x, y);
			x++;
		}
		y++;
	}
}

void	play_game(t_game *game)
{
	ft_render_winwow(game->map);
	mlx_key_hook(game->mlx, key_hook, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	ft_render_texture_img(t_map *map, t_textures *texture, int x, int y)
{
	if (map->grid[y][x] == '1')
	{
		if (mlx_image_to_window(texture->mlx, texture->img_wall, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == '0' || map->grid[y][x] == 'P')
	{
		if (mlx_image_to_window(texture->mlx, texture->img_field, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'P')
	{
		if (mlx_image_to_window(texture->mlx, texture->img_player, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'C')
	{
		if (mlx_image_to_window(texture->mlx, texture->img_ball, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'E')
	{
		if (mlx_image_to_window(texture->mlx, texture->img_exit, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
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

t_player	*get_player(void)
{
	static t_player	player;

	return (&player);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	
		t_game *game = param;

	

		if ((keydata.key == 87 || keydata.key == 119)
			&& keydata.action == MLX_PRESS)

	{
		puts("up ");
		game->texture->img_player->instances[0].y -= SIZE_IMG;
		// move_up(player);
	}
	else if ((keydata.key == 115 || keydata.key == 83)
			&& keydata.action == MLX_PRESS)

	{
		puts("down ");
		// move_down(player);
		game->texture->img_player->instances[0].y += SIZE_IMG;
	}
	else if ((keydata.key == 97 || keydata.key == 65)
			&& keydata.action == MLX_PRESS)
	{
		puts("left");
		game->texture->img_player->instances[0].x -= SIZE_IMG;
		// move_left(player);
	}
	else if ((keydata.key == 100 || keydata.key == 68)
			&& keydata.action == MLX_PRESS)
	{
		game->texture->img_player->instances[0].x += SIZE_IMG;
		puts("right ");
		// move_right(player);
	}
}