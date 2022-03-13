/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:20:53 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:44 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen((char *)s);
	while (n >= 0 && s[n] != (char)c)
		n--;
	if (n == -1)
		return (NULL);
	else
		return ((char *)&s[n]);
}
