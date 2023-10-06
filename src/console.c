/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/06 15:49:35 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	show_command(void)
{
	char	c;
	int		command;

	printf("W / ⬆   - UP \n");
	printf("S / ⬇   - DOWN \n");
	printf("A / ◀️   - LEFT \n");
	printf("D / ▶️   - RIGHT \n");
	printf("Esc     - Exit \n");
	printf("choose a direction : \n");
	scanf("%c", &c);
	command = c;
	if (command != 'w' && command != 'W' && command != 'A' && command != 'a'
		&& command != 's' && command != 'S' && command != 'D' && command != 'd'
		&& command != 27 && command != 113 && command != 10)
	{
		printf("Invalid direction! \n");
		return (-2);
	}
	return (command);
}

// void	update_game(t_map *map, t_player *player, t_player *enemy)
// {
// 	int		input;
// 	int		input_e;
// 	time_t	t;

// 	int	move_count;
// 	srand((unsigned)time(&t));
// 	// t_textures info;
// 	move_count = 0;
// 	while (true)
// 	{
// 		// mlx_key_hook(info.mlx, &move, NULL);
// 		system("clear");
// 		printf(" \n    Collectables  %i/%i \n", player->count_c, map->count_c);
// 		printf(" \n   your current moves are  %i moves \n", move_count);
// 		show_grid(map);
// 		input_e = rand() % 5;
// 		move_auto(enemy, map, input_e);
// 		// ft_render_winwow(map);
// 		input = show_command();
// 		// exit game
// 		if (input == 27)
// 			break ;
// 		if (can_move(player, map, input))
// 		{
// 			move(player, input);
// 			// move_count++;
// 		}
// 		if (map->grid[player->y][player->x] == 'C')
// 		{
// 			player->count_c = player->count_c + 1;
// 			move_count++;
// 		}
// 		else if (map->grid[player->y][player->x] == 'E'
// 				&& player->count_c == map->count_c)
// 		{
// 			move_count++;
// 			printf("you won!\n");
// 			break ;
// 		}
// 		else if (map->grid[player->y][player->x] == map->grid[enemy->y][enemy->x])
// 		{
// 			printf("you Lost!\n");
// 			move_count++;
// 			break ;
// 		}
// 		else if (map->grid[player->y][player->x] == '0')
// 			move_count++;
// 		// move_count++;

// 		if (player->prev_y >= 0)
// 			map->grid[player->prev_y][player->prev_x] = '0';
// 		// if (enemy->prev_y >= 0)
// 		// 	map->grid[enemy->prev_y][enemy->prev_x] = '0';
// 		map->grid[player->y][player->x] = 'P';
// 		// map->grid[enemy->y][enemy->x] = '*';
// 	}
// }

// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }








// void	update_game(t_map *map, t_player *player, t_player *enemy)
// {
// 	int			input;
// 	int			input_e;
// 	int			move_count;
// 	 time_t		t;

	 
// 	srand((unsigned)time(&t));
// 	move_count = 0;
// 	system("clear");
// 	printf(" \n    Collectables  %i/%i \n", player->count_c, map->count_c);
// 	printf(" \n   your current moves are  %i moves \n", move_count);
// 	// show_grid(map);
	// input_e = rand() % 4;
	// move_auto(enemy, map, input_e);
// 	// ft_render_winwow(map);
// 	input = show_command();
// 	// exit game
// 	if (input == 27)
// 		exit(0);
// 		// break ;
// 		if (can_move(player, map, input))
// 			move(player, input);
// 	if (map->grid[player->y][player->x] == 'C')
// 	{
// 		player->count_c = player->count_c + 1;
// 		move_count++;
// 	}
// 	else if (map->grid[player->y][player->x] == 'E'
// 			&& player->count_c == map->count_c)
// 	{
// 		move_count++;
// 		printf("you won!\n");
// 		exit(0);
// 		// break ;
// 	}
// 	else if (map->grid[player->y][player->x] == map->grid[enemy->y][enemy->x])
// 	{
// 		printf("you Lost!\n");
// 		move_count++;
// 		exit(0);
// 		// break ;
// 	}
// 	else if (map->grid[player->y][player->x] == '0')
// 		move_count++;
// 	if (player->prev_y >= 0)
// 		map->grid[player->prev_y][player->prev_x] = '0';
// 	if (enemy->prev_y >= 0)
// 		map->grid[enemy->prev_y][enemy->prev_x] = '0';
// 	map->grid[player->y][player->x] = 'P';
// 	map->grid[enemy->y][enemy->x] = '*';
// }
