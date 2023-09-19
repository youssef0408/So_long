/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/19 15:59:16 by yothmani         ###   ########.fr       */
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
	int		fd;
	int		result;
	char	*file_name;

	file_name = "src/map.ber";
	parse_file(file_name);
	fd = open("src/map.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR1\n");
		exit(1);
	}
	result = map_check(fd);
	close(fd);
	if (result != 0)
	{
		exit(1);
	}
}
static	size_t real_len(char *s)
{
	size_t i;

	i = 0;
	while(s[i] != '\n' && s[i] != '\0')
		i++;
	return(i);
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


bool	parse_file(char *file_path)
{
	int		fd;
	char	*current_line;
	bool	has_error;
	size_t	line_length;

	has_error = false;
	fd = open(file_path, O_RDONLY);
	current_line = get_next_line(fd);
	if (fd < 0 || real_len(current_line) == 0)
	{
		perror("ERROR\n");
		free(current_line);
		close(fd);
		return (true);
	}
	while (current_line != NULL && has_error == false)
	{
		line_length = real_len(current_line);
		if(line_length != 0)
			printf("%s", current_line);
		if (line_length != real_len(current_line))
		{
			perror("Error, your map is not rectangular\n");
			has_error = true;
		}
		if (ft_strlen(current_line) != ft_strlen(get_next_line(fd)))
			{
				printf("%zu\n", ft_strlen(current_line));
				printf("%zu\n", ft_strlen(get_next_line(fd)));
				perror("wooooooooooooow\n");
			}
		free(current_line);
		current_line = get_next_line(fd);
	}
	free(current_line);
	close(fd);
	return (has_error);
}

int	map_check(int fd)
{
	int		count_e;
	int		count_p;
	int		count_c;
	char	current_char;

	count_e = 0;
	count_p = 0;
	count_c = 0;
	while (read(fd, &current_char, 1) > 0)
	{
		if (current_char != '1' && current_char != '0' && current_char != 'C'
			&& current_char != 'E' && current_char != 'P'
			&& current_char != '\n')
		{
			perror("Error2\n");
			close(fd);
			return (1);
		}
		if (current_char == 'E')
		{
			count_e++;
			if (count_e > 1)
			{
				perror("Error3\n");
				close(fd);
				return (1);
			}
		}
		if (current_char == 'P')
		{
			count_p++;
			if (count_p > 1)
			{
				perror("Error4\n");
				close(fd);
				return (1);
			}
		}
		if (current_char == 'C')
		{
			count_c++;
		}
	}
	if (count_c < 1)
	{
		perror("Error5\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
