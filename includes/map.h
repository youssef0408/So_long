/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:54:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/28 20:21:58 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <unistd.h>

typedef struct s_map
{
	size_t	height;
	size_t	width;
	// char	**grid;
	char	*grid[100];
	// char	grid[100][100];
	 char	**map_table;
	int		p_x;
	int		p_y;

	int		e_x;
	int		e_y;

	int		count_c;
	bool	has_p;
	bool	has_e;
}			t_map;

typedef struct s_textures
{
	mlx_t* mlx;

	mlx_texture_t* texture_player;
	mlx_texture_t* texture_wall;
	mlx_texture_t* texture_collecion;
	mlx_texture_t* texture_exit;

	mlx_image_t* img_player;
	mlx_image_t* img_wall;
	int type;
}			t_textures;

void		init_map(t_map *mat);
int			row_check(char *str, t_map *mat);
int			col_check(char *str, t_map *mat, size_t row_idx, size_t col_idx);
bool		parse_file(t_map *mat, int fd);
void		show_grid(t_map *map);
bool		check_first_line(char *current_line, t_map *mat, int fd);
bool		check_last_line(char *current_line, char *previous_line, t_map *mat,
				int fd);

#endif