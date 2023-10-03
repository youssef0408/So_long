/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/03 18:30:45 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(char *file_name, t_map *mat)
{
	int	fd;

	fd = open_file(file_name);
	if (fd < 0)
		perror("Error openning file \n");
	if (parse_file(mat, fd))
		perror("Error Parsing file \n");
}

// int	main(void)
// {
// 	char		*file_name;
// 	t_map		mat;
// 	t_player	player;
// 	t_player	enemy;

// 	file_name = "src/map.ber";
// 	init_map(&mat);

// 	init_game(file_name, &mat);
// 	init_player(&player, mat.p_x, mat.p_y);
// 	init_player(&enemy, mat.m_x, mat.m_y);
// 	// console
// 	update_game(&mat, &player, &enemy);
// }

// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int	main(void)
{
	char *file_name;
	// t_player *player;
	// t_player enemy;

	t_game game;
	// game = (t_game){
	// 	.map = NULL};
	init_map2(&game);

	// game.texture = info

	file_name = "src/map.ber";
	// init_map(&game.map);
	// init_map(game->map);
	init_game(file_name, &game.map);

	// printf("ffff %c", game.map.grid[0][0]);
	play_game(&game);

	return (EXIT_SUCCESS);
}