/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:24:34 by yothmani          #+#    #+#             */
/*   Updated: 2023/03/03 13:43:52 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		first;
	int		i;
	int		last;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	first = i;
	last = (ft_strlen(s1));
	while (last > first && ft_strchr(set, s1[last - 1]))
		last--;
	s2 = malloc(sizeof(char) * (last - first + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (first < last)
	{
		s2[i] = s1[first++];
		i += 1;
	}
	s2[i] = '\0';
	return (s2);
}
