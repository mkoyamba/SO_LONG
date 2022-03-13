/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:45:03 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:32:05 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	mk_isinset(char c, char const *set)
{
	size_t	n;

	n = 0;
	while (set[n])
	{
		if (c == set[n])
			return (1);
		n++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && mk_isinset(s1[begin], set))
		begin++;
	while (end > 1 && mk_isinset(s1[end - 1], set))
		end--;
	if (begin == ft_strlen(s1))
		return (ft_strdup(""));
	return (ft_substr(s1, begin, end - begin));
}
