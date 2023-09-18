/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:48:32 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/18 13:49:51 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_read_line(char *line, int fd, char *buffer)
{
	int	nb_char;

	nb_char = read(fd, buffer, BUFFER_SIZE);
	if (nb_char <= 0)
	{
		if (!line[0])
		{
			free(line);
			line = NULL;
		}
		return (line);
	}
	while (nb_char > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
		nb_char = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_char] = 0;
	}
	return (line);
}

char	*ft_forward_line(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	j = ++i;
	while (line[i] != '\0')
		i++;
	tmp = (char *)malloc((i - j + 1) * sizeof(char));
	tmp[i - j] = 0;
	i = -1;
	j--;
	while (line[++j] != '\0')
		tmp[++i] = line[j];
	free(line);
	return (tmp);
}

size_t	ft_line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	char		*line2read;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
	{
		if (line)
		{
			free(line);
			line = NULL;
		}
		free(buffer);
		return (NULL);
	}
	if (!line)
		line = (char *)ft_calloc(1, 1);
	if (!(ft_strchr(line, '\n')))
		line = ft_read_line(line, fd, buffer);
	line2read = ft_substr(line, 0, ft_line_len(line));
	line = ft_forward_line(line);
	if (!line2read)
		free(line);
	free(buffer);
	return (line2read);
}
