/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:57:45 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/22 22:40:59 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*newcontent;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = lst;
	newlst = NULL;
	while (head)
	{
		newcontent = f(head->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		head = head->next;
	}
	return (newlst);
}
