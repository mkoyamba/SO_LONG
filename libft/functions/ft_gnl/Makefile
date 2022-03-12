# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:43:23 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/01 11:46:17 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE = 42

FLAGS = -Wall -Wextra -Werror

NAME = ../../libs/ft_gnl.a

INCLUDES = includes/get_next_line.h

SRC =	srcs/get_next_line.c\
		srcs/get_next_line_utils.c\



OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re