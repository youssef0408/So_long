/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:54:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/22 00:24:26 by yothmani         ###   ########.fr       */
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

int			line_check2(char *str, t_map *mat);
bool		parse_file2(char *file_path, t_map *mat);
void	    show_grid(t_map *map);

#endif