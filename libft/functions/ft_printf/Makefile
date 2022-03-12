# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 14:16:15 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/01 11:24:05 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = ../../libs/ft_printf.a

INCLUDES = includes/ft_printf.h

SRC =	srcs/ft_printf.c\
		srcs/ft_flag_bx.c\
		srcs/ft_flag_c.c\
		srcs/ft_flag_d.c\
		srcs/ft_flag_i.c\
		srcs/ft_flag_p.c\
		srcs/ft_flag_perc.c\
		srcs/ft_flag_s.c\
		srcs/ft_flag_u.c\
		srcs/ft_flag_x.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re