/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/24 18:56:27 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main2(void)
// {
// 	t_map	my_map;
// 	int		result;
// 	char	*str;

// 	my_map.height = 5;
// 	my_map.width = 4;
// 	my_map.count_c = 0;
// 	my_map.has_p = false;
// 	my_map.has_e = false;
// 	str = "1001";
// 	result = line_check2(str, &my_map);
// 	printf("result is = , %i", result);
// }

int	main(void)
{
	char	*file_name;
	t_map	mat;

	init_map(&mat);
	file_name = "src/map.ber";
	init_game(file_name, &mat);
	// show_grid(&mat);
	update_game(&mat);
	// input = show_command();
	// printf("======%i\n", input);
	return (0);
}

int	show_command(void)
{
	char	c;
	int		asciiValue;

	printf("W - UP \n");
	printf("S - DOWN \n");
	printf("A - LEFT \n");
	printf("D - RIGHT \n");
	printf("Q - Exit \n");
	printf("Enter a character to find its ASCII value: ");
	scanf("%c", &c);
	asciiValue = c;
	if (asciiValue != 87 && asciiValue != 65 && asciiValue != 83
		&& asciiValue != 68 && asciiValue != 119 && asciiValue != 97
		&& asciiValue != 115 && asciiValue != 100 && asciiValue != 81
		&& asciiValue != 113)
		return (-2);
	return (asciiValue);
}

void	init_game(char *file_name,
				t_map *mat)
{
	int	fd;

	// init_map(&mat);
	fd = open_file(file_name);
	if (fd < 0)
		perror("Error  Open file \n");
	if (parse_file(mat, fd))
		perror("Error Parsig file \n");
}

size_t	real_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

// void	init_game(void)
// {
// 	char	*file_name;

// 	file_name = "src/map.ber";
// 	//  read file
// 	// parse file line by line
// 	// parse_file(file_name);
// 	map_check(file_name);
// 	// generate map array
// }

void	update_game(t_map *mat)
{
	int	input;

	// handle game state
	// handle movement
	// handle pickups
	while (true)
	{
		show_grid(mat);
		input = show_command();
		if (input < 0)
		{
			perror("Error Invalid direction \n");
		}
		if (input == 81 || input == 113)
			break ;
	}
}

// int	line_check(char *str, size_t mat_width, size_t *mat_height,
//	int *count_c,
// 		bool *has_p, bool *has_e)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (-1);
// 	if (mat_width != real_len(str))
// 		return (-2);
// 	if (str[0] != '1' || str[mat_width - 1] != '1')
// 	{
// 		return (-8);
// 	}
// 	while (str[i] && i < mat_width - 1)
// 	{
// 		if (*mat_height == 0 && str[i] != '1')
// 			return (-9);
// 		else if (str[i] == 'E')
// 		{
// 			if (*has_e)
// 				return (-3);
// 			else
// 				*has_e = true;
// 		}
// 		else if (str[i] == 'P')
// 		{
// 			if (*has_p)
// 				return (-4);
// 			else
// 				*has_p = true;
// 		}
// 		else if (str[i] == 'C')
// 		{
// 			*count_c = *count_c + 1;
// 		}
// 		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
// 			return (-5);
// 		i++;
// 	}
// 	*mat_height = *mat_height + 1;
// 	return (0);
// }

// bool	parse_file(char *file_path)
// {
// 	int		fd;
// 	char	*current_line;
// 	char	*previous_line;
// 	bool	has_p;
// 	bool	has_e;
// 	int		count_c;
// 	bool	has_error;
// 	size_t	mat_height;
// 	size_t	mat_width;
// 	int		check;
// 	size_t	i;

// 	has_p = false;
// 	has_e = false;
// 	count_c = 0;
// 	has_error = false;
// 	has_p = false;
// 	has_e = false;
// 	count_c = 0;
// 	mat_height = 0;
// 	i = 0;
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		close(fd);
// 		return (true);
// 	}
// 	current_line = get_next_line(fd);
// 	if (real_len(current_line) == 0)
// 	{
// 		free(current_line);
// 		close(fd);
// 		return (true);
// 	}
// 	mat_width = real_len(current_line);
// 	check = line_check(current_line, mat_width, &mat_height, &count_c, &has_p,
// 			&has_e);
// 	if (check < 0)
// 	{
// 		free(current_line);
// 		close(fd);
// 		return (true);
// 	}
// 	printf("%s", current_line);
// 	while (current_line != NULL && has_error == false)
// 	{
// 		previous_line = current_line;
// 		current_line = get_next_line(fd);
// 		if (current_line == NULL)
// 		{
// 			if (previous_line[mat_width] == '\n')
// 				return (true);
// 			while (i < mat_width - 1)
// 			{
// 				if (previous_line[i] != '1')
// 					return (true);
// 				i++;
// 			}
// 			free(current_line);
// 			close(fd);
// 			if (count_c == 0 || !has_p || !has_e)
// 				return (true);
// 			return (false);
// 		}
// 		check = line_check(current_line, mat_width, &mat_height, &count_c,
// 				&has_p, &has_e);
// 		if (check < 0)
// 		{
// 			has_error = true;
// 			free(current_line);
// 			close(fd);
// 			return (true);
// 		}
// 		printf("%s", current_line);
// 	}
// 	printf("  current = %s\n", current_line);
// 	return (has_error);
// }
