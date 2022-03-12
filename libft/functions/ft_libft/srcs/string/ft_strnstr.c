/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:59:36 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:38 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	check(const char *haystack, const char *needle, size_t n)
{	
	int	v;
	int	g;

	v = 1;
	g = 0;
	while (needle[g] != '\0' )
	{
		if (needle[g] != haystack[n + g])
			v = 0;
		g++;
	}
	return (v);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	n;

	c = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	else if (haystack[0] == '\0' || len < 1 || (haystack[0] == '\0'
			&& (needle[0] != '\0')))
		return (NULL);
	while (haystack[c] != '\0' )
		c++;
	n = 0;
	while (n < c - 1 && n < len - 1)
	{
		if (needle[0] == haystack[n] && n + ft_strlen(needle) <= len)
		{
			if (check(haystack, needle, n) == 1)
				return ((char *)haystack + n);
		}
		n++;
	}
	if (ft_strlen(needle) == 1 && needle[0] == haystack[0])
		return ((char *) haystack);
	return (NULL);
}
