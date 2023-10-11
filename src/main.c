/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/11 16:58:00 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	clean_texture(t_game game)
{
	mlx_delete_texture(game.texture.texture_collectables);
	mlx_delete_texture(game.texture.texture_ennemy);
	mlx_delete_texture(game.texture.texture_exit);
	mlx_delete_texture(game.texture.texture_floor);
	mlx_delete_texture(game.texture.texture_loser);
	mlx_delete_texture(game.texture.texture_player);
	mlx_delete_texture(game.texture.texture_win);
	mlx_delete_texture(game.texture.texture_wall);
	return ;
}

void	show_grid(t_map *map)
{
	size_t	i;
	size_t	j;
	char	obj;

	i = 0;
	printf("\n");
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			obj = map->grid[i][j];
			if (i == 0 || i == map->height - 1)
				printf("█");
			else if (obj == '0')
				printf(" ");
			else if (obj == '1')
				printf("█");
			else if (obj == 'M')
				printf("*");
			else
				printf("%c", obj);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	char	*file_name;
	t_game	game;
	time_t	t;

	srand((unsigned)time(&t));
	file_name = generate_file_name();
	init_map2(&game);
	// free(file_name);
	if (!init_game(file_name, &game.map))
	{
		free(file_name);
		free_map(game.map.grid, game.map.height);	
		return (-1);
	}
	init_player(&game.player, game.map.p_x, game.map.p_y);
	init_player(&game.enemy, game.map.m_x, game.map.m_y);
	if(!map_is_playable(&game))
	{
		printf("MAP IS NOT PLAYABLE!\n");
		free(file_name);
		free_map(game.map.grid, game.map.height);
		return(-1);
	}
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
	clean_texture(game);
	free(file_name);	
	file_name = NULL;
	return 0;
}
