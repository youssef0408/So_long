/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/02 18:11:37 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}


void	ft_create_texture(t_textures *info)
{
	info->texture_player = mlx_load_png("includes/textures/chuki.png");
	info->texture_wall = mlx_load_png("includes/textures/wall.png");
	info->texture_field = mlx_load_png("includes/textures/field.png");
	info->texture_ball = mlx_load_png("includes/textures/ball.png");
	info->texture_exit = mlx_load_png("includes/textures/Exit.png");
	if (!info->texture_player)
		error();
	if (!info->texture_wall)
		error();
	if (!info->texture_field)
		error();
	if (!info->texture_ball)
		error();
	if (!info->texture_exit)
		error();
	info->img_player = mlx_texture_to_image(info->mlx, info->texture_player);
	info->img_wall = mlx_texture_to_image(info->mlx, info->texture_wall);
	info->img_field = mlx_texture_to_image(info->mlx, info->texture_field);
	info->img_ball = mlx_texture_to_image(info->mlx, info->texture_ball);
	info->img_exit = mlx_texture_to_image(info->mlx, info->texture_exit);
	mlx_resize_image(info->img_player, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(info->img_wall, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(info->img_field, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(info->img_ball, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(info->img_exit, SIZE_IMG, SIZE_IMG);
}

void	ft_render_winwow(t_map *map)
{
	size_t		x;
	size_t		y;
	t_textures	info;

	if (!(info.mlx = mlx_init((map->width) * SIZE_IMG, map->height * SIZE_IMG,"so_long", false)))
	{
		puts(mlx_strerror(10));
		return ;
	}
	ft_create_texture(&info);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_render_texture_img(map, &info, x, y);
			x++;
		}
		y++;
	}
	mlx_key_hook(info.mlx, key_hook, NULL);
	mlx_loop(info.mlx);
	// mlx_delete_texture(info.texture_player);
	// mlx_delete_texture(info.texture_wall);
	// mlx_delete_texture(info.texture_field);
	// mlx_delete_texture(info.texture_ball);
	// mlx_delete_texture(info.texture_exit);
	mlx_terminate(info.mlx);
}

void	ft_render_texture_img(t_map *map, t_textures *info, int x, int y)
{
	if (map->grid[y][x] == '1')
	{
		if (mlx_image_to_window(info->mlx, info->img_wall, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'P')
	{
		if (mlx_image_to_window(info->mlx, info->img_player, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == '0')
	{
		if (mlx_image_to_window(info->mlx, info->img_field, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'C')
	{
		if (mlx_image_to_window(info->mlx, info->img_ball, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'E')
	{
		if (mlx_image_to_window(info->mlx, info->img_exit, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
}

char	**ft_create_render_map(t_map *mat, int fd)
{
	char **table;
	char *str;
	int i;

	table = ft_calloc(sizeof(char *), (mat->height + 1)); //height
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
	return(&player);
}


void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_player	*player;
	(void)param;
	player = get_player();
		printf("hi");
	if (keydata.key == 87 || keydata.key == 119)
	{
		move_up(player);
	}
	else if (keydata.key == 115 || keydata.key == 83)
	{
		move_down(player);
	}
	else if (keydata.key == 97 || keydata.key == 65)
	{
		move_left(player);
	}
	else if (keydata.key == 100 || keydata.key == 68)
	{
		move_right(player);
	}
}