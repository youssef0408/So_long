/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 01:55:45 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	*file_name;
	t_game	game;
	time_t	t;

	srand((unsigned)time(&t));
	file_name = "src/maps/map0.ber";
	init_map2(&game);
	if (!init_game(file_name, &game.map))
	{
		free_map(game.map.grid, game.map.height);
		return (-1);
	}
	init_player(&game.player, game.map.p_x, game.map.p_y);
	
	if (!map_is_playable(&game))
	{
		printf("MAP IS NOT PLAYABLE!\n");
		free_map(game.map.grid, game.map.height);
		return (-1);
	}
	init_map2(&game);
	if (!init_game(file_name, &game.map))
	{
		free_map(game.map.grid, game.map.height);
		return (-1);
	}
	init_player(&game.player, game.map.p_x, game.map.p_y);
	
	play_game(&game);
	free_map(game.map.grid, game.map.height);
	return (0);
}
