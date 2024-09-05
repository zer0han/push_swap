# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 16:48:25 by rdalal            #+#    #+#              #
#    Updated: 2024/07/09 16:48:25 by rdalal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES	= push_swap.h

SRCS	= error_handling.c init_a_to_b.c  main.c \
		stack_init.c push_swap.c utils_stack.c \
		init_b_to_a.c push.c

AR	= ar rcs

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS) $(INCLUDES)
			$(AR) $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean