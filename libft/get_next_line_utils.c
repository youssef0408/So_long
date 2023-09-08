/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:35:35 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/07 18:23:49 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*arr;
	size_t	i;

	i = -1;
	arr = malloc(elsize * nelem);
	if (!arr)
		return (NULL);
	if (nelem != 0)
	{
		while (++i < nelem)
			arr[i] = 0;
		return ((void *)arr);
	}
	return ((void *)arr);
}

char	*ft_strchr(char *s, int c)
{
	if (s)
	{
		while (s && *s != '\0')
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
		if (*s == (char)c)
			return ((char *)s);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		size_concat;
	char	*concat;
	int		i;
	int		j;

	i = -1;
	j = -1;
	size_concat = ft_strlen(s1) + ft_strlen(s2);
	concat = (char *)ft_calloc((size_concat + 1), sizeof(char));
	while (s1[++i])
		concat[i] = s1[i];
	while (s2[++j])
		concat[i + j] = s2[j];
	if (s1)
		free(s1);
	return (concat);
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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}