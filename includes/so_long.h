/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:18 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/11 15:05:59 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "./file.h"
# include "./map.h"
# include "./mlx_utils.h"
# include "./parse.h"
# include "./player.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# define SIZE_IMG 50

bool	init_game(char *file_name, t_map *map);
size_t	real_len(char *s);

#endif
