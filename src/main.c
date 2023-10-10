/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/09 20:10:25 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	init_game(char *file_name, t_map *map)
{
	int	fd;

	fd = open_file(file_name);
	if (fd < 0)
	{
		close(fd);
		perror("Error openning file \n");
		return (false);
	}
	if (!parse_file(map, fd))
	{
		// close(fd);
		free_map(map->grid, map->height);
		file_name = NULL;
		perror("Error Parsing file \n");
		return (false);
	}
	return (true);
}

int	main(void)
{
	char	*file_name;
	t_game	game;

	// time_t	t;
	// srand((unsigned)time(&t));
	// file_name = generate_file_name();
	file_name = "src/maps/map0.ber";
	// game.map.map_size = get_map_height(file_name);
	// free(file_name);
	init_map2(&game);
	// // game.map.grid = map_malloc(game.map.grid, game.map.map_size);
	if (!init_game(file_name, &game.map))
	{
		// free_map(game.map.grid, game.map.height);
		return (-1);
	}
	// free(game.map.grid);
	init_player(&game.player, game.map.p_x, game.map.p_y);
	init_player(&game.enemy, game.map.m_x, game.map.m_y);
	play_game(&game);
	// free_map(game.map.grid, height);
	// free(file_name);
	free_map(game.map.grid, game.map.height);
	file_name = NULL;
	// free(game.map.grid);
}
