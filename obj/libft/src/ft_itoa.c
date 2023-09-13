/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:01:57 by yothmani          #+#    #+#             */
/*   Updated: 2023/02/24 17:05:59 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_cases(int n)
{
	int				i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		i = 2;
		num = -n;
	}
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*tab;
	int				i;

	tab = malloc((num_cases(n)) + 1);
	if ((!tab))
		return (NULL);
	i = num_cases(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		tab[0] = '-';
	}
	tab[i] = '\0';
	tab[i - 1] = '0';
	while (num > 0)
	{
		i--;
		tab[i] = num % 10 + 48;
		num /= 10;
	}
	return (tab);
}
