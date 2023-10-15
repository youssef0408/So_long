/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:29:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/15 00:44:30 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# define SIZE_IMG 75

# define REAL_POS_X 0
# define REAL_POS_Y 1
# define MAP_POS_X 2
# define MAP_POS_Y 3

typedef struct s_map
{
	size_t				height;
	size_t				width;
	char				**grid;
	size_t				map_size;
	int					p_x;
	int					p_y;
	int					m_x;
	int					m_y;
	size_t				e_x;
	size_t				e_y;
	int					is_possible;
	int					items;
	int					count_c;
	bool				has_p;
	bool				has_e;
	bool				has_m;
}						t_map;
typedef struct s_player
{
	int					x;
	int					y;
	int					prev_x;
	int					prev_y;
	int					count_c;
	int					count_move;
}						t_player;

typedef struct s_textures
{
	mlx_texture_t		*texture_player;
	mlx_texture_t		*texture_wall;
	mlx_texture_t		*texture_floor;
	mlx_texture_t		*texture_collectables;
	mlx_texture_t		*texture_exit_open;
	mlx_texture_t		*texture_exit_close;
	mlx_texture_t		*texture_ennemy;
	mlx_texture_t		*texture_ennemy2;
	mlx_texture_t		*texture_win;
	mlx_texture_t		*texture_loser;

	mlx_image_t			*img_win;
	mlx_image_t			*img_loser;
	mlx_image_t			*img_player;
	mlx_image_t			*img_wall;
	mlx_image_t			*img_floor;
	mlx_image_t			*img_collectables;
	mlx_image_t			*img_exit_open;
	mlx_image_t			*img_exit_close;
	mlx_image_t			*img_ennemy;
	mlx_image_t			*img_ennemy2;
	mlx_image_t			*g_img_p_move;
	mlx_image_t			*g_img_nb_coll;
	mlx_image_t			*g_img_win;
	mlx_image_t			*g_img_coll_str;
	mlx_image_t			*g_img_slash_str;
	mlx_image_t			*g_img_move_str;
	mlx_image_t			*g_img_total_str;

	int					type;
}						t_textures;

typedef struct s_game
{
	mlx_t				*mlx;
	struct s_map		map;
	struct s_textures	texture;
	struct s_player		player;
	struct s_player		enemy;
	struct s_player		enemy2;
	bool				g_stop_action;
	int					g_timer;

}						t_game;

void					init_player(t_player *player, int x, int y);
bool					init_game(char *file_name, t_map *map);
size_t					real_len(char *s);
int						row_check(char *str, t_map *map);
int						col_check(char *str, t_map *map, size_t row_idx,
							size_t col_idx);
bool					parse_file(t_map *map, int fd);
bool					check_first_line(char *current_line, t_map *map,
							int fd);
bool					check_last_line(char *current_line, char *previous_line,
							t_map *map, int fd);
void					load_textures(t_game *game);
void					create_texture_images(t_game *game);
void					resize_images(t_game *game);
void					ft_create_texture(t_game *game);
void					ft_render_window(t_game *game);
void					key_hook(mlx_key_data_t keydata, void *param);
void					play_game(t_game *game);
void					ft_render_texture_img(t_game *game, size_t x, size_t y);
void					delete_c_img(t_game *game);
void					delete_c_img(t_game *game);
void					show_move_count(t_game *game);
void					show_items_count(t_game *game);
void					win_or_lose(t_game *game, size_t x, size_t y);
void					enemy_moves(void *(param));
void					kill_player(t_game *game, size_t x, size_t y);
int						errror(void);
void					clean_images(t_game game);
void					display_collectables_and_moves(t_game *game);
int						row_check(char *str, t_map *map);
int						col_check(char *str, t_map *map, size_t row_idx,
							size_t col_idx);
bool					parse_file(t_map *map, int fd);
bool					check_first_line(char *current_line, t_map *map,
							int fd);
bool					check_last_line(char *current_line, char *previous_line,
							t_map *map, int fd);
void					populate_row(char *str, size_t row_idx, t_map *map);

size_t					real_len(char *s);

void					init_map(t_game *game);
int						initialize_game_data(t_game *game, char *file_name);
bool					is_position_valid(t_game *game, size_t x, size_t y);
void					path_finder(t_game *game, size_t x, size_t y);
bool					map_is_playable(t_game *game);
void					clean_texture(t_game game);
void					full_free(t_game game, char *file_name);

int						open_file(char *file_path);
void					free_file(char *str, int fd);
void					free_map(char **grid, size_t height);
int						get_exit(t_map *map, size_t row_idx, size_t col_idx);
int						get_player(t_map *map, size_t row_idx, size_t col_idx);
int						get_ennemy(t_map *map, size_t row_idx, size_t col_idx);
void					update_img_pos(t_game *game, size_t x, size_t y);
void					enemy_moves_up(int input, t_game *game,
							int map_positions[4]);
void					enemy_moves_left(int input, t_game *game,
							int map_positions[4]);
void					enemy_moves_right(int input, t_game *game,
							int map_positions[4]);
void					enemy_moves(void *param);
void					toggle_img(t_game *game);
void					key_hook_up(t_game *game, int map_pos_x, int map_pos_y,
							mlx_key_data_t keydata);
void					key_hook_down(t_game *game, int map_pos_x,
							int map_pos_y, mlx_key_data_t keydata);
void					key_hook_right(t_game *game, int map_pos_x,
							int map_pos_y, mlx_key_data_t keydata);
void					key_hook_left(t_game *game, int map_pos_x,
							int map_pos_y, mlx_key_data_t keydata);

#endif