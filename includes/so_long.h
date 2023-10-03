/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:18 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/03 19:16:32 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include <../MLX42/include/MLX42/MLX42.h>
# include "so_long.h"
# include "./map.h"
# include "./player.h"
# include "./file.h"
# include "./mlx_utils.h"
# include "./parse.h"
# include "./console.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# define SIZE_IMG 50

void	init_game(char *file_name, t_map *mat);
size_t	real_len(char *s);

#endif
