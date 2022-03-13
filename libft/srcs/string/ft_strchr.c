/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:04:02 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:06 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n] != (char)c && s[n] != '\0')
		n++;
	if (s[n] == '\0' && (char)c != '\0')
		return (NULL);
	else
		return ((char *)&s[n]);
}
