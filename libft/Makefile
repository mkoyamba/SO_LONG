# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 10:35:41 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/30 11:37:19 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -fsanitize=address -D BUFFER_SIZE=42

NAME = libft.a

INCLUDES =	includes/libft.h \

ABS =		srcs/abs/ft_itoa.c \
			srcs/abs/ft_putchar_fd.c \
			srcs/abs/ft_putendl_fd.c \
			srcs/abs/ft_putnbr_fd.c \
			srcs/abs/ft_putstr_fd.c \
			srcs/abs/ft_split.c \
			srcs/abs/ft_striteri.c \
			srcs/abs/ft_strjoin.c \
			srcs/abs/ft_strmapi.c \
			srcs/abs/ft_strtrim.c \
			srcs/abs/ft_substr.c \

CTYPE =		srcs/ctype/ft_isalnum.c \
			srcs/ctype/ft_isalpha.c \
			srcs/ctype/ft_isascii.c \
			srcs/ctype/ft_isdigit.c \
			srcs/ctype/ft_isprint.c \
			srcs/ctype/ft_tolower.c \
			srcs/ctype/ft_toupper.c \

LST =		srcs/lst/ft_lstadd_back.c \
			srcs/lst/ft_lstadd_front.c \
			srcs/lst/ft_lstclear.c \
			srcs/lst/ft_lstdelone.c \
			srcs/lst/ft_lstiter.c \
			srcs/lst/ft_lstlast.c \
			srcs/lst/ft_lstmap.c \
			srcs/lst/ft_lstnew.c \
			srcs/lst/ft_lstsize.c \

STDLIB =	srcs/stdlib/ft_atoi.c \
			srcs/stdlib/ft_calloc.c \

STRING =	srcs/string/ft_bzero.c \
			srcs/string/ft_memchr.c \
			srcs/string/ft_memcmp.c \
			srcs/string/ft_memcpy.c \
			srcs/string/ft_memmove.c \
			srcs/string/ft_memset.c \
			srcs/string/ft_strchr.c \
			srcs/string/ft_strdup.c \
			srcs/string/ft_strlcat.c \
			srcs/string/ft_strlcpy.c \
			srcs/string/ft_strlen.c \
			srcs/string/ft_strncmp.c \
			srcs/string/ft_strnstr.c \
			srcs/string/ft_strrchr.c \

GNL =		srcs/gnl/get_next_line.c \
			srcs/gnl/get_next_line_utils.c \

PRINTF =	srcs/printf/ft_flag_bx.c \
			srcs/printf/ft_flag_c.c \
			srcs/printf/ft_flag_d.c \
			srcs/printf/ft_flag_i.c \
			srcs/printf/ft_flag_p.c \
			srcs/printf/ft_flag_perc.c \
			srcs/printf/ft_flag_s.c \
			srcs/printf/ft_flag_u.c \
			srcs/printf/ft_flag_x.c \
			srcs/printf/ft_printf.c \

SRC = $(ABS) $(CTYPE) $(LST) $(STDLIB) $(STRING) $(GNL) $(PRINTF)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\033[32;1m\n\nLibft created\n\n"

%.o: %.c
	@printf "\033[31;1m."
	@gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, bonus, re