# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 12:30:30 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/14 11:14:00 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address

MLX_FLAGS = -framework OpenGL -framework AppKit

NAME = so_long

INCLUDES =	includes/so_long.h\

LIB =	libft/libft.a

MLX = minilibx/libmlx.a

SRC =	srcs/main.c \
#		srcs/map_init.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx
	gcc $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	
%.o: %.c
	gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean:
	make -C libft fclean
#	make -C minilibx clean
	rm -rf $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, bonus, re