/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:25:13 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/12 20:36:21 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	load_textures(t_game *game);
void	create_texture_images(t_game *game);
void	resize_images(t_game *game);
void	ft_create_texture(t_game *game);
void	ft_render_window(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	play_game(t_game *game);
void	ft_render_texture_img(t_game *game, size_t x, size_t y);
void	delete_c_img(t_game *game);
void	show_move_count(t_game *game);
void	show_items_count(t_game *game);
void	win_or_lose(t_game *game, size_t x, size_t y);
int		errror(void);
void	clean_images(t_game game);
void	display_collectables_and_moves(t_game *game);


#endif