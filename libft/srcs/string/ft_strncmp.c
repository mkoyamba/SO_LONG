/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:54:40 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:35 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	while (s1[a] == s2[a] && a < n && s1[a] && s2[a])
		a++;
	if (a == n || s1[a] == s2[a])
		return (0);
	if (s2[a] > s1[a] && s1[a] >= 0 && s2[a] >= 0)
		return (-1);
	else
		return (1);
}
