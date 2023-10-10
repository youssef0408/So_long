/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:48:32 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/09 16:53:05 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_read_line(char *line, int fd, char *buffer)
// {
// 	int	nb_char;

// 	nb_char = read(fd, buffer, BUFFER_SIZE);
// 	if (nb_char <= 0)
// 	{
// 		if (!line[0])
// 		{
// 			free(line);
// 			line = NULL;
// 		}
// 		return (line);
// 	}
// 	while (nb_char > 0)
// 	{
// 		line = ft_strjoin(line, buffer);
// 		if (ft_strchr(line, '\n'))
// 			break ;
// 		nb_char = read(fd, buffer, BUFFER_SIZE);
// 		buffer[nb_char] = 0;
// 	}
// 	return (line);
// }

// char	*ft_forward_line(char *line)
// {
// 	char	*tmp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (!line)
// 		return (NULL);
// 	while (line[i] != '\0' && line[i] != '\n')
// 		i++;
// 	if (!line[i])
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	j = ++i;
// 	while (line[i] != '\0')
// 		i++;
// 	tmp = (char *)malloc((i - j + 1) * sizeof(char));
// 	tmp[i - j] = 0;
// 	i = -1;
// 	j--;
// 	while (line[++j] != '\0')
// 		tmp[++i] = line[j];
// 	free(line);
// 	return (tmp);
// }

// size_t	ft_line_len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0' && str[i] != '\n')
// 		i++;
// 	i++;
// 	return (i);
// }

// char	*get_next_line(int fd)
// {
// 	char		*buffer;
// 	static char	*line;
// 	char		*line2read;

// 	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
// 	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
// 	{
// 		if (line)
// 		{
// 			free(line);
// 			line = NULL;
// 		}
// 		free(buffer);
// 		return (NULL);
// 	}
// 	if (!line)
// 		line = (char *)ft_calloc(1, 1);
// 	if (!(ft_strchr(line, '\n')))
// 		line = ft_read_line(line, fd, buffer);
// 	line2read = ft_substr(line, 0, ft_line_len(line));
// 	line = ft_forward_line(line);
// 	if (!line2read)
// 		free(line);
// 	free(buffer);
// 	free(line);
// 	return (line2read);
// }

char	*get_before_newline(const char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof *res);
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
	}
	return (res);
}

char	*get_after_newline(const char *str)
{
	char	*res;
	int		ii;
	int		i;

	i = 0;
	ii = 0;
	while (str && str[ii])
		ii++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res = ft_malloc_zero((ii - i) + 1, sizeof *res);
	if (!res)
	{
		return (NULL);
	}
	ii = 0;
	while (str[i + ii])
	{
		res[ii] = str[i + ii];
		ii++;
	}
	return (res);
}

void	ft_read_line(int fd, char **save, char **temporary)
{
	char	*buf;
	int		status;

	buf = malloc(sizeof *buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	status = 1;
	while (status > 0)
	{
		status = read(fd, buf, BUFFER_SIZE);
		if (status == -1)
		{
			ft_strs_cleans(&buf, save, temporary);
			return ;
		}
		buf[status] = '\0';
		*temporary = ft_strdup(*save);
		ft_strs_cleans(save, 0, 0);
		*save = ft_join_strs(*temporary, buf);
		ft_strs_cleans(temporary, 0, 0);
		if (ft_contains_newline(*save))
			break ;
	}
	ft_strs_cleans(&buf, 0, 0);
}

char	*ft_parse_line(char **save, char **temporary)
{
	char	*line;

	*temporary = ft_strdup(*save);
	ft_strs_cleans(save, 0, 0);
	*save = get_after_newline(*temporary);
	line = get_before_newline(*temporary);
	ft_strs_cleans(temporary, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	char *line;
	char *temporary;
	static char *save = NULL;

	line = NULL;
	temporary = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_line(fd, &save, &temporary);
	if (save && *save != '\0')
	{
		line = ft_parse_line(&save, &temporary);
	}
	if (!line || *line == '\0')
	{
		ft_strs_cleans(&save, &line, &temporary);
		return (NULL);
	}
	return (line);
}