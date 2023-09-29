/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:18 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/28 20:56:52 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <../MLX42/include/MLX42/MLX42.h>
# include "../lib/libft/libft.h"
# include "./file.h"
# include "./map.h"
# include "./player.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
#include <stdio.h>

# define SIZE_IMG 25
// typedef struct s_map
// {
// 	size_t	height;
// 	size_t	width;
// 	int		p_x;
// 	int		p_y;

// 	int		e_x;
// 	int		e_y;

// 	int		count_c;
// 	bool	has_p;
// 	bool	has_e;
// }			t_map;

void	init_game(char *file_name, t_map *mat);
// bool		parse_file(char *file_path);
void	update_game(t_map *mat, t_player *player);
int		show_command(void);
size_t	real_len(char *s);
// int			line_check(char *str, size_t mat_width, size_t *mat_height,
// 				int *count_c, bool *has_p, bool *has_e);
void	error_42(void);
int		map_check(int fd);
int		check_map_is_rectangular(char *file_name);

#endif
