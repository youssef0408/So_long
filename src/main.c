/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 17:52:48 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	char	*file_name;
	t_game	game;
	int		i;

	if (argc != 2)
		errror();
	file_name = argv[1];
	i = ft_strlen(file_name);
	if (argv[1][i - 1] != 'r' && argv[1][i - 2] != 'e' && argv[1][i - 3] != 'b'
		&& argv[1][i - 4] != '.')
	{
		printf("error\n");
		return (-1);
	}
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
	if (!map_is_playable(game))
	{
		printf("MAP IS NOT PLAYABLE!\n");
		return (-1);
	}
	init_map(game);
	if (!init_game(file_name, &game->map))
		return (-1);
	init_player(&game->player, game->map.p_x, game->map.p_y);
	return (0);
}
