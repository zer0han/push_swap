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

NAME	=	push_swap

CC	= gcc

CFLAGS = -Wextra -Wall -Werror

HEAD	= inlcudes/	

SRCS_PS	= error_handling.c init_a_to_b.c \
		stack_init.c push_swap.c utils_stack.c \
		init_b_to_a.c push.c reverse_rotate.c \
		rotate.c swap.c sort_algo.c sort_three.c

SRCS_PATH	=	srcs/

SRCS	=	$(addprefix $(SRCS_PATH), $(SRCS_PS))

LIBFT_H_PATH	= libft/includes/

LIBFT_PATH	=	libft/

LIBFT	= $(LIBFT_PATH)libft.a

$(LIBFT):
			$(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME):  $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(LIBFT) -o $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD) -I$(LIBFT_H_PATH)

clean:
			rm -f $(OBJS)
			$(MAKE) -C $(LIBFT_PATH)

fclean: clean
			rm -f $(NAME)
			$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean