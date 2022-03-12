/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:30:39 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 11:46:42 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buff);
char	*ft_get_line(char *str);
char	*ft_update(char *str);

#endif