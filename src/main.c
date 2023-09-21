/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/20 21:03:08 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	init_game();
	return (0);
}

void	init_game(void)
{
	char	*file_name;

	// int		fd;
	// int		result;
	file_name = "src/map.ber";
	if (parse_file(file_name))
		perror("ERROR\n");
	// result = map_check(fd);
	// 	if (result != 0)
	// 	{
	// 		exit(1);
	// 	}
	// return (0);
}

static size_t	real_len(char *s)
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

void	update_game(void)
{
	// handle game state
	// handle movement
	// handle pickups
}

int	line_check(char *str, size_t mat_width, int count_c, bool has_p, bool has_e)
{
	if (!str)
		return (-1);
	if (mat_width != real_len(str))
		return (-2);
	while (*str)
	{
		if (*str == 'E')
		{
			if (has_e)
				return (-3);
			else
				has_e = true;
		}
		else if (*str == 'P')
		{
			if (has_p)
				return (-4);
			else
				has_p = true;
		}
		else if (*str == 'C')
		{
			count_c++;
		}
		else if (*str != '1' && *str != '0' && *str != '\n')
			return (-5);
		str++;
	}
	return (0);
}

bool	parse_file(char *file_path)
{
	int		fd;
	char	*current_line;
	bool	has_p;
	bool	has_e;
	int		count_c;
	bool	has_error;
	size_t	mat_width;

	has_error = false;
	has_p = false;
	has_e = false;
	count_c = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (true);
	}
	current_line = get_next_line(fd);
	if (real_len(current_line) == 0)
	{
		free(current_line);
		close(fd);
		return (true);
	}
	mat_width = real_len(current_line);
	if (line_check(current_line, mat_width, count_c, has_p, has_e) < 0)
	{
		free(current_line);
		close(fd);
		return (true);
	}
	printf("%s", current_line);
	while (current_line != NULL && has_error == false)
	{
		current_line = get_next_line(fd);
		if (line_check(current_line, mat_width, count_c, has_p, has_e) < 0)
		{
			has_error = true;
			free(current_line);
			close(fd);
			return (true);
		}
		printf("%s", current_line);
	}
	free(current_line);
	close(fd);
	if (count_c == 0)
		has_error = true;
	return (has_error);
}

// int	map_check(int fd)
// {
// 	int		count_e;
// 	int		count_p;
// 	int		count_c;
// 	char	current_char;

// 	count_e = 0;
// 	count_p = 0;
// 	count_c = 0;
// 	while (read(fd, &current_char, 1) > 0)
// 	{
// 		if (current_char != '1' && current_char != '0' && current_char != 'C'
// 			&& current_char != 'E' && current_char != 'P'
// 			&& current_char != '\n')
// 		{
// 			perror("Error2\n");
// 			close(fd);
// 			return (1);
// 		}
// 		if (current_char == 'E')
// 		{
// 			count_e++;
// 			if (count_e > 1)
// 			{
// 				perror("Error3\n");
// 				close(fd);
// 				return (1);
// 			}
// 		}
// 		if (current_char == 'P')
// 		{
// 			count_p++;
// 			if (count_p > 1)
// 			{
// 				perror("Error4\n");
// 				close(fd);
// 				return (1);
// 			}
// 		}
// 		if (current_char == 'C')
// 		{
// 			count_c++;
// 		}
// 	}
// 	if (count_c < 1)
// 	{
// 		perror("Error5\n");
// 		close(fd);
// 		return (1);
// 	}
// 	close(fd);
// 	return (0);
// }
