/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:33:31 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:17 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = 0;
	while (src[n] != '\0' && n < dstsize - 1 && dstsize != 0)
	{
		dst[n] = src[n];
		n++;
	}
	if (dstsize != 0)
		dst[n] = '\0';
	return ((size_t)ft_strlen(src));
}
