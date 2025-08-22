/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:26:35 by whwang            #+#    #+#             */
/*   Updated: 2025/04/08 19:03:22 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	head = 0;
	while (lst)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			return (0);
		temp->content = f(lst->content);
		if (!(temp->content))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		temp->next = 0;
		if (head == 0)
			head = temp;
		else
			ft_lstadd_back(&head, temp);
		lst = lst->next;
	}
	return (head);
}
