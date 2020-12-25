# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroland <rroland@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 19:44:25 by rroland           #+#    #+#              #
#    Updated: 2020/12/25 17:54:21 by rroland          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGC = -Wall -Wextra -Werror -c -I ./

SOURCES = dop_func.c ft_printf.c read_str.c find_flags.c find_type.c \
type_sdicp.c type_uxX%.c type_di.c

SOURCE_BONUS = dop_func.c ft_printf.c read_str.c find_flags.c find_type.c \
type_sdicp.c type_uxX%.c type_di.c

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCE_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGC) -c $< -o $@

$(NAME):$(OBJECTS)
	ar rc $@ $^
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(OBJECTS_BONUS)
		ar rc $(NAME) $^
		ranlib $(NAME)

.PHONY: all clean fclean re bonus