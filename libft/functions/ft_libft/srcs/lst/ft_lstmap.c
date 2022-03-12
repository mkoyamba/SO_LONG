/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:39:50 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:33:07 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	mk_lstiter(t_list *lst, void *(*f)(void *))
{
	t_list	*follow;

	follow = lst;
	while (follow)
	{
		follow->content = f(follow->content);
		follow = follow->next;
	}
}

static t_list	*mk_lstdup(t_list *lst)
{
	t_list	*dup;
	t_list	*temp_dup;
	t_list	*temp_lst;

	dup = malloc(sizeof(t_list));
	if (!dup)
		return (NULL);
	dup->content = lst->content;
	dup->next = NULL;
	temp_dup = dup;
	temp_lst = lst->next;
	while (temp_lst)
	{
		ft_lstadd_back(&dup, ft_lstnew(temp_lst->content));
		temp_dup = temp_dup->next;
		temp_lst = temp_lst->next;
	}
	return (dup);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;

	if (!lst)
		return (NULL);
	result = mk_lstdup(lst);
	if (!result)
	{
		del(lst);
		return (NULL);
	}
	mk_lstiter(result, f);
	return (result);
}
