/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:25:13 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/03 12:22:51 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	ft_create_texture(t_textures *texture);
void	ft_render_winwow(t_map *map);
char	**ft_create_render_map(t_map *mat, int fd);
void	key_hook(mlx_key_data_t keydata, void *param);
void	play_game(t_game *game);
void	ft_render_texture_img(t_map *map, t_textures *texture, int x, int y);
#endif