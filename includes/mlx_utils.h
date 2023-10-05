/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:25:13 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/04 21:13:37 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

// void	ft_create_texture(t_textures *texture);
void	ft_create_texture(t_game *game);
void	ft_render_window(t_game *game);
char	**ft_create_render_map(t_map *mat, int fd);
void	key_hook(mlx_key_data_t keydata, void *param);
void	play_game(t_game *game);
void	ft_render_texture_img(t_game *game, int x, int y);
void	delete_c_img(t_game *game);
void	show_move(t_game *game);
void	show_nb_col(t_game *game);
void	win_condition(t_game *game, int x, int y);
#endif