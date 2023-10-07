/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/07 16:05:39 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	init_game(char *file_name, t_map *map)
{
	int	fd;

	fd = open_file(file_name);
	if (fd < 0)
	{
		perror("Error openning file \n");
		return (false);
	}
	if (!parse_file(map, fd))
	{
		perror("Error Parsing file \n");
		return (false);
	}
	return (true);
}

// int	main(void)
// {
// 	char		*file_name;
// 	t_map		map;
// 	t_player	player;
// 	t_player	enemy;

// 	file_name = "src/map.ber";
// 	init_map(&map);

// 	init_game(file_name, &map);
// 	init_player(&player, map.p_x, map.p_y);
// 	init_player(&enemy, map.m_x, map.m_y);
// 	// console
// 	update_game(&map, &player, &enemy);
// }

// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int	main(void)
{
	char	*file_name;
	t_game	game;
	time_t	t;
	int		map_rand;

	srand((unsigned)time(&t));
	map_rand = rand() % 4;
	file_name = "src/maps/map";
	file_name = ft_strjoin(file_name, ft_itoa(map_rand));
	file_name = ft_strjoin(file_name, ".ber");
	file_name = "src/maps/map0.ber";
	init_map2(&game);
	if (!init_game(file_name, &game.map))
	{
		
		free(file_name);
		return (-1);
	}
	init_player(&game.player, game.map.p_x, game.map.p_y);
	init_player(&game.enemy, game.map.m_x, game.map.m_y);
	play_game(&game);
	free(file_name);
	
	return (EXIT_SUCCESS);
}
