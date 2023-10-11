/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_and_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:50:53 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/11 16:37:41 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game);
void	create_texture_images(t_game *game);
void	resize_images(t_game *game);

void	ft_create_texture(t_game *game)
{
	load_textures(game);
	create_texture_images(game);
	resize_images(game);
}

void	load_textures(t_game *game)
{
	game->texture.texture_player = mlx_load_png("includes/textures/NURSE.png");
	game->texture.texture_wall = mlx_load_png("includes/textures/wall2.0.png");
	game->texture.texture_floor = mlx_load_png("includes/textures/terrain.png");
	game->texture.texture_collectables = mlx_load_png("includes/textures/syringe-147034_640.png");
	game->texture.texture_exit = mlx_load_png("./includes/textures/sortie.png");
	game->texture.texture_ennemy =
		mlx_load_png("includes/textures/covid.png");
	game->texture.texture_win = mlx_load_png("./includes/textures/winner.png");
	game->texture.texture_loser = mlx_load_png("./includes/textures/loser.png");
	if (!game->texture.texture_win || !game->texture.texture_loser
		|| !game->texture.texture_player || !game->texture.texture_wall
		|| !game->texture.texture_floor || !game->texture.texture_collectables
		|| !game->texture.texture_exit || !game->texture.texture_ennemy)
	{
		errror();
	}
}

void	create_texture_images(t_game *game)
{
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
}

void	ft_render_texture_img(t_game *game, size_t x, size_t y)
{
	if (mlx_image_to_window(game->mlx, game->texture.img_floor, x * SIZE_IMG, y
			* SIZE_IMG) < 0)
		errror();
	if (game->map.grid[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->texture.img_wall, x * SIZE_IMG,
				y * SIZE_IMG) < 0)
			errror();
	}
	else if (game->map.grid[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->texture.img_collectables, x
				* SIZE_IMG, y * SIZE_IMG) < 0)
			errror();
	}
}

void	resize_images(t_game *game)
{
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
