# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 10:35:41 by mkoyamba          #+#    #+#              #
#    Updated: 2022/03/01 11:24:11 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = ../../libs/ft_libft.a

INCLUDES = includes/libft.h

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

SRC = $(ABS) $(CTYPE) $(LST) $(STDLIB) $(STRING)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, bonus, re