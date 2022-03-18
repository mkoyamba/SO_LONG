# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 12:30:30 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/18 10:46:38 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address

MLX_FLAGS = -framework OpenGL -framework AppKit

NAME = so_long

INCLUDES =	includes/so_long.h \

INCLUDES_B =	includes/so_long_bonus.h \

LIB =	libft/libft.a

MLX = minilibx/libmlx.a

SRC =	srcs/main.c \
		srcs/end_game.c \
		srcs/init/fd_init.c \
		srcs/init/img_init.c \
		srcs/init/null_init.c \
		srcs/init/mlx_init.c \
		srcs/init/map/map_init.c \
		srcs/init/map/map_check.c \
		srcs/game/so_long.c \
		srcs/game/events.c \

BONUS = bonus/main_bonus.c \
		bonus/end_game_bonus.c \
		bonus/init/fd_init_bonus.c \
		bonus/init/img_init_bonus.c \
		bonus/init/null_init_bonus.c \
		bonus/init/mlx_init_bonus.c \
		bonus/init/bonus_init_bonus.c \
		bonus/init/map/map_init_bonus.c \
		bonus/init/map/map_check_bonus.c \
		bonus/game/so_long_bonus.c \
		bonus/game/events_bonus.c \
		bonus/game/events_enemy_bonus.c \
		bonus/game/evolve_bonus.c \

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:bonus.c=bonus.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx
	@make -C libft
	gcc $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

%bonus.o: %bonus.c
	gcc $(CFLAGS) -I $(INCLUDES_B) -c $< -o $@
	
%.o: %.c
	gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@


bonus: $(OBJB)
	@make -C minilibx
	@make -C libft
	gcc $(CFLAGS) $(MLX_FLAGS) $(OBJB) $(LIB) $(MLX) -o $(NAME)

clean:
	@make -C libft clean
	@rm -rf $(OBJ) $(OBJB)

fclean:
	@make -C libft fclean
	@make -C minilibx clean
	@rm -rf $(OBJ) $(OBJB)
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, bonus, re