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

SRCS	=

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