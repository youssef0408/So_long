/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clean_up_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:14:20 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 03:48:50 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	clean_texture(t_game game)
{
	mlx_delete_texture(game.texture.texture_collectables);
	mlx_delete_texture(game.texture.texture_ennemy);
	mlx_delete_texture(game.texture.texture_ennemy2);
	mlx_delete_texture(game.texture.texture_exit_close);
	mlx_delete_texture(game.texture.texture_exit_open);
	mlx_delete_texture(game.texture.texture_floor);
	mlx_delete_texture(game.texture.texture_loser);
	mlx_delete_texture(game.texture.texture_player);
	mlx_delete_texture(game.texture.texture_win);
	mlx_delete_texture(game.texture.texture_wall);
	return ;
}

void	clean_images(t_game game)
{
	mlx_delete_image(game.mlx, game.texture.img_collectables);
	mlx_delete_image(game.mlx, game.texture.img_ennemy);
	mlx_delete_image(game.mlx, game.texture.img_ennemy2);
	mlx_delete_image(game.mlx, game.texture.img_player);
	mlx_delete_image(game.mlx, game.texture.img_exit_open);
	mlx_delete_image(game.mlx, game.texture.img_exit_close);
	mlx_delete_image(game.mlx, game.texture.img_floor);
	mlx_delete_image(game.mlx, game.texture.img_loser);
	mlx_delete_image(game.mlx, game.texture.img_wall);
	mlx_delete_image(game.mlx, game.texture.img_win);
	mlx_delete_image(game.mlx, game.texture.g_img_win);
	mlx_delete_image(game.mlx, game.texture.g_img_nb_coll);
	mlx_delete_image(game.mlx, game.texture.g_img_p_move);
	mlx_delete_image(game.mlx, game.texture.g_img_total_str);
	mlx_delete_image(game.mlx, game.texture.g_img_slash_str);
	mlx_delete_image(game.mlx, game.texture.g_img_move_str);
	mlx_delete_image(game.mlx, game.texture.g_img_coll_str);
}
