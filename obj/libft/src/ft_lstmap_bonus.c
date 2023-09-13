/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:04:02 by yothmani          #+#    #+#             */
/*   Updated: 2023/03/06 10:39:08 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*new_elem;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	first_elem = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			ft_lstclear(&first_elem, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&first_elem, new_elem);
		lst = lst->next;
	}
	return (first_elem);
}
