/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:25:13 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/02 18:03:02 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	ft_create_texture(t_textures *info);
void	ft_render_winwow(t_map *map);
void	ft_render_texture_img(t_map *map, t_textures *info, int x, int y);
char	**ft_create_render_map(t_map *mat, int fd);
void	key_hook(mlx_key_data_t keydata, void* param);
t_player	*get_player(void);



#endif