# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 14:26:29 by gisidro-          #+#    #+#              #
#    Updated: 2025/10/20 14:48:00 by gisidro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	main.c \
		stack_init.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		error_free.c \
		list_utils.c \
		malloc.c \
		normalize.c \
		radix.c \
		tiny_sort.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_atoll.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
