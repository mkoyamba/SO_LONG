/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:04:33 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:32:57 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*follow;
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	follow = (*lst)->next;
	ft_lstdelone(*lst, del);
	while (follow)
	{
		temp = follow->next;
		ft_lstdelone(follow, del);
		follow = temp;
	}
	*lst = NULL;
}
