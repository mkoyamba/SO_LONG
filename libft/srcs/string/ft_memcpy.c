/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:21 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:33:49 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*tdst;
	char	*tsrc;
	size_t	a;

	if (!src && !dst && n != 0)
		return (NULL);
	tdst = (char *)dst;
	tsrc = (char *)src;
	a = 0;
	while (a < n)
	{
		tdst[a] = tsrc[a];
		a++;
	}
	return (dst);
}
