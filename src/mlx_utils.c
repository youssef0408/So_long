/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/10 01:51:26 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		errror();
	if (mlx_image_to_window(game->mlx, game->texture.img_player, game->map.p_x
			* SIZE_IMG, game->map.p_y * SIZE_IMG) < 0)
		errror();
	if (mlx_image_to_window(game->mlx, game->texture.img_ennemy, game->map.m_x
			* SIZE_IMG, game->map.m_y * SIZE_IMG) < 0)
		errror();
}

void	show_items_count(t_game *game)
{
	char	*nbc;

	if (game->texture.g_img_nb_coll)
	{
		mlx_delete_image(game->mlx, game->texture.g_img_nb_coll);
	}
	nbc = ft_itoa(game->player.count_c);
	game->texture.g_img_nb_coll = mlx_put_string(game->mlx, nbc, SIZE_IMG * 5,
			(game->map.height * SIZE_IMG) + 25);
	free(nbc);
	nbc = NULL;
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

int	errror()
{
	puts(mlx_strerror(mlx_errno));
	exit(-1);
}
