/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:54:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/24 17:24:12 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_map
{
	size_t	height;
	size_t	width;
	char	*grid[100];
	// char	grid[100][100];
	int		p_x;
	int		p_y;

	int		e_x;
	int		e_y;

	int		count_c;
	bool	has_p;
	bool	has_e;
}			t_map;

void		init_map(t_map *mat);
int			row_check(char *str, t_map *mat);
int			col_check(char *str, t_map *mat, size_t row_idx, size_t col_idx);
bool		parse_file(t_map *mat, int fd);
void		show_grid(t_map *map);
bool		check_first_line(char *current_line, t_map *mat, int fd);
bool		check_last_line(char *current_line, char *previous_line, t_map *mat,
				int fd);

#endif