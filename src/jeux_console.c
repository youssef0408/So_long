/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeux_console.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:08:40 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/10 00:39:21 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void	init_player(t_player *player, t_map map)
// {
// 	player->x = map.p_x;
// 	player->y = map.p_y;
// 	player->count_c = 0;
// 	player->prev_x = -1;
// 	player->prev_y = -1;
// }

// void	show_grid(t_map *map)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	obj;

// 	i = 0;
// 	printf("\n");
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			obj = map->grid[i][j];
// 			if (i == 0 || i == map->height - 1)
// 				printf("█");
// 			else if (obj == '0')
// 				printf(" ");
// 			else if (obj == '1')
// 				printf("█");
// 			else if (obj == 'M')
// 				printf("*");
// 			else
// 				printf("%c", obj);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

// void	init_map(t_map *map)
// {
// 	map->height = 0;
// 	map->width = 0;
// 	map->has_p = false;
// 	map->has_e = false;
// 	map->count_c = 0;
// }

// void	move(t_player *player, int input)
// {
// 	player->prev_x = player->x;
// 	player->prev_y = player->y;
// 	if (input == 87 || input == 119)
// 	{
// 		move_up(player);
// 	}
// 	else if (input == 115 || input == 83)
// 	{
// 		move_down(player);
// 	}
// 	else if (input == 97 || input == 65)
// 	{
// 		move_left(player);
// 	}
// 	else if (input == 100 || input == 68)
// 	{
// 		move_right(player);
// 	}
// }

// void	move_auto(t_player *enemy, t_map *map, int input)
// {
// 	bool	has_moved;

// 	has_moved = false;
// 	enemy->prev_x = enemy->x;
// 	enemy->prev_y = enemy->y;
// 	input = 1;
// 	printf("unput   %i\n", input);
// 	printf(" 0 up pos   %c\n", map->grid[enemy->y - 1][enemy->x]);
// 	printf(" 1 down pos   %c\n", map->grid[enemy->y + 1][enemy->x]);
// 	printf(" 2 left pos   %c\n", map->grid[enemy->y][enemy->x - 1]);
// 	printf(" 3 right pos  %c\n", map->grid[enemy->y][enemy->x + 1]);
// 	if (input == 0 && map->grid[enemy->y - 1][enemy->x] != '1'
// 		&& map->grid[enemy->y - 1][enemy->x] != 'C' && map->grid[enemy->y
// 		- 1][enemy->x] != 'E')
// 	{
// 		move_up(enemy);
// 		has_moved = true;
// 	}
// 	else if (input == 1 && map->grid[enemy->y + 1][enemy->x] != '1'
// 			&& map->grid[enemy->y + 1][enemy->x] == 'C' &&
// 				map->grid[enemy->y + 1][enemy->x] != 'E')
// 	{
// 		move_down(enemy);
// 		has_moved = true;
// 	}
// 	else if (input == 2 && map->grid[enemy->y][enemy->x - 1] != '1'
// 			&& map->grid[enemy->y][enemy->x - 1] != 'C' &&
// 				map->grid[enemy->y][enemy->x - 1] != 'E')
// 	{
// 		move_left(enemy);
// 		has_moved = true;
// 	}
// 	else if (input == 3 && map->grid[enemy->y][enemy->x + 1] != '1'
// 			&& map->grid[enemy->y][enemy->x + 1] != 'C'
// 			&& map->grid[enemy->y][enemy->x + 1] != 'E')
// 	{
// 		move_right(enemy);
// 		has_moved = true;
// 	}
// 	if (has_moved)
// 	{
// 		map->grid[enemy->prev_y][enemy->prev_x] = '0';
// 		map->grid[enemy->y][enemy->x] = '*';
// 	}
// }

// void	move_up(t_player *player)
// {
// 	player->y = player->y - 1;
// }

// void	move_down(t_player *player)
// {
// 	player->y = player->y + 1;
// }

// void	move_left(t_player *player)
// {
// 	player->x = player->x - 1;
// }

// void	move_right(t_player *player)
// {
// 	player->x = player->x + 1;
// }

// bool	can_move(t_player *player, t_map *map, int input)
// {
// 	if (input < 0)
// 	{
// 		perror("Error Invalid direction \n");
// 		return (false);
// 	}
// 	else if ((input == 87 || input == 119) && (map->grid[player->y
// 				- 1][player->x] == '1'))
// 	{
// 		return (false);
// 	}
// 	else if ((input == 115 || input == 83) && (map->grid[player->y
// 				+ 1][player->x] == '1'))
// 	{
// 		return (false);
// 	}
// 	else if ((input == 97 || input == 65) && (map->grid[player->y][player->x
// 				- 1] == '1'))
// 	{
// 		return (false);
// 	}
// 	else if ((input == 100 || input == 68) && (map->grid[player->y][player->x
// 				+ 1] == '1'))
// 	{
// 		return (false);
// 	}
// 	else if (can_exit(player, map, input) == false)
// 		return (false);
// 	return (true);
// }

// bool	can_exit(t_player *player, t_map *map, int input)
// {
// 	if ((input == 87 || input == 119) && (map->grid[player->y
// 			- 1][player->x] == 'E'))
// 	{
// 		if (player->count_c < map->count_c)
// 		{
// 			perror("you can't exit the game without all the colectables!\n");
// 			return (false);
// 		}
// 		return (true);
// 	}
// 	else if ((input == 115 || input == 83) && (map->grid[player->y
// 				+ 1][player->x] == 'E'))
// 	{
// 		if (player->count_c < map->count_c)
// 		{
// 			perror("you can't exit the game without all the colectables!\n");
// 			return (false);
// 		}
// 		return (true);
// 	}
// 	else if ((input == 97 || input == 65) && (map->grid[player->y][player->x
// 				- 1] == 'E'))
// 	{
// 		if (player->count_c < map->count_c)
// 		{
// 			perror("you can't exit the game without all the colectables!\n");
// 			return (false);
// 		}
// 		return (true);
// 	}
// 	else if ((input == 100 || input == 68) && (map->grid[player->y][player->x
// 				+ 1] == 'E'))
// 	{
// 		if (player->count_c < map->count_c)
// 		{
// 			perror("you can't exit the game without all the colectables!\n");
// 			return (false);
// 		}
// 		return (true);
// 	}
// 	return (true);
// }

// int	show_command(void)
// {
// 	char	c;
// 	int		command;

// 	printf("W / ⬆   - UP \n");
// 	printf("S / ⬇   - DOWN \n");
// 	printf("A / ◀️   - LEFT \n");
// 	printf("D / ▶️   - RIGHT \n");
// 	printf("Esc     - Exit \n");
// 	printf("choose a direction : \n");
// 	scanf("%c", &c);
// 	command = c;
// 	if (command != 'w' && command != 'W' && command != 'A' && command != 'a'
// 		&& command != 's' && command != 'S' && command != 'D' && command != 'd'
// 		&& command != 27 && command != 113 && command != 10)
// 	{
// 		printf("Invalid direction! \n");
// 		return (-2);
// 	}
// 	return (command);
// }

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
// 		time_t		t;

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
