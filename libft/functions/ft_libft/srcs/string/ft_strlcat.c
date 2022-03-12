/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:13:50 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:15 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dest;
	const char	*source;
	size_t		n;
	size_t		lendest;

	dest = dst;
	n = dstsize;
	source = src;
	while (n-- != 0 && *dest != '\0')
		dest++;
	lendest = dest - dst;
	n = dstsize - lendest;
	if (n == 0)
		return (lendest + ft_strlen(source));
	while (*source != '\0')
	{
		if (n != 1)
		{
			*dest++ = *source;
			n--;
		}
		source++;
	}
	*dest = '\0';
	return (lendest + (source - src));
}
