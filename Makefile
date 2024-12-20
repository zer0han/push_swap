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

HEAD	= includes/

SRCS_C	= push.c reverse_rotate.c rotate.c swap.c

SRCS_UTLS	=	error_handling.c init_a_to_b.c \
				init_b_to_a.c push_swap.c sort_algo.c \
				sort_three.c stack_init.c utils_stack.c

SRCS_C_PATH	= srcs/commands/
SRCS_UTLS_PATH	= srcs/utils/

SRCS	=	$(addprefix $(SRCS_C_PATH), $(SRCS_C)) \
			$(addprefix $(SRCS_UTLS_PATH), $(SRCS_UTLS))

LIBFT_H_PATH	= libft/includes/

LIBFT_PATH	=	libft/

LIBFT	= $(LIBFT_PATH)libft.a

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_PATH)

$(NAME):	$(OBJS) $(LIBFT) $(HEAD)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD) -I$(LIBFT_H_PATH)

clean:	libft-clean root-clean

libft-clean:
			$(MAKE) -C $(LIBFT_PATH) clean
	
root-clean:
			rm -f $(OBJS)

fclean: libft-fclean root-fclean

libft-fclean:
			$(MAKE) -C $(LIBFT_PATH) fclean

root-fclean: root-clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft libft-clean libft-fclean root-clean root-fclean
