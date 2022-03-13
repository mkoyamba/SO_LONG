/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:30:32 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:31:56 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	mk_free(char **result, int a)
{
	int	n;

	n = 0;
	while (n < a)
	{
		free(result[n]);
		n++;
	}
	free(result);
}

static int	mk_word(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (c == '\0')
			return (1);
		if (s[i] != '\0' && s[i] != c)
			n++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] == c)
			i++;
	}
	return (n);
}

static char	*mk_strpush(const char *s, char c, int *n)
{
	int		i;
	int		g;
	char	*tab;
	int		len;

	g = 0;
	while (s[*n] != '\0' && s[*n] == c)
		*n = *n + 1;
	i = *n;
	while (s[i] != '\0' && s[i] != c)
		i++;
	len = i - *n;
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (g < len && s[*n] != '\0')
	{
		tab[g] = s[*n];
		g++;
		*n = *n + 1;
	}
	tab[g] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n;
	int		a;

	result = malloc((mk_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	n = 0;
	a = 0;
	while (a < mk_word(s, c))
	{
		result[a] = mk_strpush(s, c, &n);
		if (!result[a])
		{
			mk_free(result, a);
			return (NULL);
		}
		a++;
	}
	result[a] = NULL;
	return (result);
}
