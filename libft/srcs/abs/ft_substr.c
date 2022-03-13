/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:28:41 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:32:09 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	char			*result;

	n = 0;
	if (!s || start >= (unsigned int)ft_strlen((char *)s))
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	while (s[start + n] && n < len)
		n++;
	result = malloc((n + 1) * sizeof(char));
	if (!result)
		return (NULL);
	n = 0;
	while (s[start + n] && n < len)
	{
		result[n] = s[start + n];
		n++;
	}
	result[n] = '\0';
	return (result);
}
