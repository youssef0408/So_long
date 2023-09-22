/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:18 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/21 22:58:20 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "./map.h"

# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

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

void	init_game(void);
// bool		parse_file(char *file_path);
void	update_game(void);

size_t	real_len(char *s);
// int			line_check(char *str, size_t mat_width, size_t *mat_height,
// 				int *count_c, bool *has_p, bool *has_e);
void	error_42(void);
int		map_check(int fd);
int		check_map_is_rectangular(char *file_name);

#endif
