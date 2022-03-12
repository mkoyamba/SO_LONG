# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:19:19 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/01 12:40:52 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC =	libs/ft_libft.a\
		libs/ft_printf.a\
		libs/ft_gnl.a\

all: $(NAME)

libs:
	mkdir libs

$(NAME): libs
	make -C functions/ft_libft
	make -C functions/ft_printf
	make -C functions/ft_gnl
	ar rc $(NAME) $(SRC)

clean:
	make -C functions/ft_libft clean
	make -C functions/ft_printf clean
	make -C functions/ft_gnl clean

fclean: clean
	make -C functions/ft_libft fclean
	make -C functions/ft_printf fclean
	make -C functions/ft_gnl fclean
	rm -rf libs
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re