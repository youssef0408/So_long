/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 04:30:20 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int32_t main(void)
{
	char	*file_name;
	t_game	game;
	time_t	t;

	srand((unsigned)time(&t));
	file_name = "bonus/maps/map0.ber";
	if (initialize_game_data(&game, file_name) == -1)
	{
		free_map(game.map.grid, game.map.height);
		return (-1);
	}
	play_game(&game);
	free_map(game.map.grid, game.map.height);
	return (0);
}

int	initialize_game_data(t_game *game, char *file_name)
{
	init_map(game);
	if (!init_game(file_name, &game->map))
		return (-1);
	init_player(&game->player, game->map.p_x, game->map.p_y);
	if (game->map.has_m)
	{
		init_player(&game->enemy, game->map.m_x, game->map.m_y);
		init_player(&game->enemy2, game->map.m_x, game->map.m_y);
	}
	if (!map_is_playable(game))
	{
		printf("MAP IS NOT PLAYABLE!\n");
		return (-1);
	}
	init_map(game);
	if (!init_game(file_name, &game->map))
		return (-1);
	init_player(&game->player, game->map.p_x, game->map.p_y);
	if (game->map.has_m)
	{
		init_player(&game->enemy, game->map.m_x, game->map.m_y);
		init_player(&game->enemy2, game->map.m_x, game->map.m_y);
	}
	return (0);
}
