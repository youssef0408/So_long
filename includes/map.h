/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:54:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/07 16:04:34 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "player.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_map
{
	size_t					height;
	size_t					width;
	char					*grid[100];
	int						p_x;
	int						p_y;
	int						m_x;
	int						m_y;

	int						e_x;
	int						e_y;

	int						count_c;
	bool					has_p;
	bool					has_e;
	bool					has_m;
}							t_map;

typedef struct s_textures
{
	mlx_texture_t			*texture_player;
	mlx_texture_t			*texture_wall;
	mlx_texture_t			*texture_floor;
	mlx_texture_t			*texture_collectables;
	mlx_texture_t			*texture_exit;
	mlx_texture_t			*texture_ennemy;
	mlx_texture_t			*texture_win;
	mlx_texture_t			*texture_loser;

	mlx_image_t				*img_win;
	mlx_image_t				*img_loser;
	mlx_image_t				*img_player;
	mlx_image_t				*img_wall;
	mlx_image_t				*img_floor;
	mlx_image_t				*img_collectables;
	mlx_image_t				*img_exit;
	mlx_image_t				*img_ennemy;
	int						type;
}							t_textures;

typedef struct s_game
{
	mlx_t					*mlx;
	struct s_map			map;
	struct s_textures		texture;
	struct s_player			player;
	struct s_player			enemy;

}							t_game;

void						init_map(t_map *map);
int							row_check(char *str, t_map *map);
int							col_check(char *str, t_map *map, size_t row_idx,
								size_t col_idx);
bool						parse_file(t_map *map, int fd);
void						show_grid(t_map *map);
bool						check_first_line(char *current_line, t_map *map,
								int fd);
bool						check_last_line(char *current_line,
								char *previous_line, t_map *map, int fd);
void						populate_row(char *str, size_t row_idx, t_map *map);

size_t						real_len(char *s);

void						init_map2(t_game *game);

#endif