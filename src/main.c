/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/10 16:52:12 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	*file_name;
	t_game	game;
	time_t	t;

	srand((unsigned)time(&t));
	file_name = generate_file_name();
	free(file_name);
	init_map2(&game);
	if (!init_game(file_name, &game.map))
	{
		free_map(game.map.grid, game.map.height);
		return (-1);
	}
	init_player(&game.player, game.map.p_x, game.map.p_y);
	init_player(&game.enemy, game.map.m_x, game.map.m_y);
	play_game(&game);
	free_map(game.map.grid, game.map.height);
	file_name = NULL;
}
