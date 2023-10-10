/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:53:34 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/09 16:53:51 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*clean_total;
	size_t			total;
	unsigned char	*str_p;

	total = count * size;
	clean_total = malloc(total);
	if (!clean_total)
	{
		return (NULL);
	}
	str_p = (unsigned char *)clean_total;
	while (total > 0)
	{
		*str_p = '\0';
		str_p++;
		total--;
	}
	return (clean_total);
}

char	*ft_strdup(const char *str_1)
{
	int		i;
	char	*str_2;

	if (!str_1)
	{
		return (ft_strdup(""));
	}
	i = 0;
	while (str_1[i])
		i++;
	str_2 = ft_malloc_zero(i + 1, sizeof *str_2);
	if (!str_2)
		return (NULL);
	i = -1;
	while (str_1[++i])
		str_2[i] = str_1[i];
	return (str_2);
}

void	ft_strs_cleans(char **str_1, char **str_2, char **str_3)
{
	if (str_1 && *str_1)
	{
		free(*str_1);
		*str_1 = NULL;
	}
	if (str_2 && *str_2)
	{
		free(*str_2);
		*str_2 = NULL;
	}
	if (str_3 && *str_3)
	{
		free(*str_3);
		*str_3 = NULL;
	}
}

int	ft_contains_newline(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join_strs(const char *str_1, const char *str_2)
{
	char *new_str;
	int len_str_1;
	int len_str_2;

	len_str_1 = 0;
	if (!str_1 && !str_2)
		return (NULL);
	while (str_1 && str_1[len_str_1])
		len_str_1++;
	len_str_2 = 0;
	while (str_2 && str_2[len_str_2])
		len_str_2++;
	new_str = ft_malloc_zero(len_str_1 + len_str_2 + 1, sizeof *new_str);
	if (!new_str)
		return (NULL);
	len_str_1 = -1;
	while (str_1 && str_1[++len_str_1])
		new_str[len_str_1] = str_1[len_str_1];
	len_str_2 = -1;
	while (str_2 && str_2[++len_str_2])
		new_str[len_str_1 + len_str_2] = str_2[len_str_2];
	return (new_str);
}