/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:31 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/16 15:28:24 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_position_valid(t_game *game, size_t x, size_t y)
{
	return (x >= 0 && x < game->map.width && y >= 0 && y < game->map.height
		&& game->map.grid[y][x] != 'V' && game->map.grid[y][x] != '1');
}

void	path_finder(t_game *game, size_t x, size_t y)
{
	if (!is_position_valid(game, x, y))
		return ;
	if (game->map.grid[y][x] == 'E')
	{
		game->map.is_possible = 1;
	}
	if (game->map.grid[y][x] == 'C')
	{
		game->map.items--;
	}
	game->map.grid[y][x] = 'V';
	path_finder(game, x, y - 1);
	path_finder(game, x, y + 1);
	path_finder(game, x + 1, y);
	path_finder(game, x - 1, y);
}

bool	map_is_playable(t_game *game)
{
	game->map.is_possible = 0;
	game->map.items = game->map.count_c;
	path_finder(game, game->map.p_x, game->map.p_y);
	if (game->map.is_possible == 1 && game->map.items == 0)
	{
		free_map(game->map.grid, game->map.height);
		return (true);
	}
	return (false);
}

void	show_move_count(t_game *game)
{
	char	*moves_count;

	system("clear");
	if (game->texture.g_img_p_move)
		mlx_delete_image(game->mlx, game->texture.g_img_p_move);
	game->player.count_move += 1;
	moves_count = ft_itoa(game->player.count_move);
	printf(" \n   your current moves are  %i moves \n",
		game->player.count_move);
	game->texture.g_img_p_move = mlx_put_string(game->mlx, moves_count, SIZE_IMG
			* 5, (game->map.height * SIZE_IMG) + 50);
	free(moves_count);
	moves_count = NULL;
}

int	errror(void)
{
	printf("Error\n");
	exit(1);
}
