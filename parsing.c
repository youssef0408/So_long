/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:14:21 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/11 21:02:07 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_42(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	parse(char *str)
{
	int	i;
	int	count_e;
	int	count_p;
	int	count_c;

	i = 0;
	count_e = 0;
	count_p = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P')
			error_42();
		if (str[i] == 'E')
		{
			count_e++;
			if (count_e > 1)
				error_42();
		}
		if (str[i] == 'P')
		{
			count_p++;
			if (count_p > 1)
				error_42();
		}
		if (str[i] == 'C')
		{
			count_c++;
		}
		i++;
	}
	if (count_c < 1)
		error_42();
	return (0);
}

int	check_map_is_rectangular(char *file_path)
{
	int		fd;
	char	*str;
	char	*next_line;
	int		is_rect;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\n");
		return (1);
	}
	str = get_next_line(fd);
	is_rect = 1;
	if (str == 0)
	{
		perror("Error\n");
		close(fd);
		return (1);
	}
	while (next_line = get_next_line(fd))
	{
		if (ft_strlen(str) != ft_strlen((next_line)))
		{
			perror("Error, your map is not rectangular\n");
			is_rect = 0;
			break ;
		}
		free(str);
		str = next_line;
	}
	free(str);
	colse(fd);
	return (is_rect);
}
