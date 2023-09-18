/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:14:21 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/18 16:07:33 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void	error_42(void)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	exit(1);
// }

// int	parse(char *file_name)
// {
// 	int	i;
// 	int	count_e;
// 	int	count_p;
// 	int	count_c;
// 	int	fd;

// 	i = 0;
// 	count_e = 0;
// 	count_p = 0;
// 	count_c = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("ERROR\n");
// 		return (true);
// 	}
// 	if (file_name[i] == '\0')
// 		return (0);
// 	while (file_name[i] != '\0')
// 	{
// 		if (file_name[i] != '0' && file_name[i] != '1' && file_name[i] != 'C'
// 			&& file_name[i] != 'E' && file_name[i] != 'P')
// 		{
// 			perror("Error\n");
// 			close(fd);
// 			return (1);
// 		}
// 		if (file_name[i] == 'E')
// 		{
// 			count_e++;
// 			if (count_e > 1)
// 			{
// 				perror("Error\n");
// 				close(fd);
// 				return (1);
// 			}
// 		}
// 		if (file_name[i] == 'P')
// 		{
// 			count_p++;
// 			if (count_p > 1)
// 			{
// 				perror("Error\n");
// 				close(fd);
// 				return (1);
// 			}
// 		}
// 		if (file_name[i] == 'C')
// 		{
// 			count_c++;
// 		}
// 		i++;
// 	}
// 	if (count_c < 1)
// 	{
// 		perror("Error\n");
// 		close(fd);
// 		return (1);
// 	}
// 	return (0);
// }

// int	check_map_is_rectangular(char *file_name)
// {
// 	int		fd;
// 	char	*str;
// 	char	*next_line;
// 	int		is_rect;

// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("ERROR\n");
// 		return (1);
// 	}
// 	str = get_next_line(fd);
// 	is_rect = 1;
// 	if (str == 0)
// 	{
// 		perror("Error\n");
// 		close(fd);
// 		return (1);
// 	}
// 	next_line = get_next_line(fd);
// 	while (next_line == get_next_line(fd))
// 	{
// 		if (ft_strlen(str) != ft_strlen((next_line)))
// 		{
// 			perror("Error, your map is not rectangular\n");
// 			is_rect = 0;
// 			break ;
// 		}
// 		free(str);
// 		str = next_line;
// 	}
// 	free(str);
// 	close(fd);
// 	return (is_rect);
// }
