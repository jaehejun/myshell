# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 15:46:56 by jaehejun          #+#    #+#              #
#    Updated: 2023/10/24 16:22:34 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

CC		= CC

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g

SRCS	= main.c\
		src/signal_handling.c\
		src/tokenize.c\
		src/check_quotes.c\
		

OBJS	= $(SRCS:.c=.o)

LIB = -L ./libft -libft

all		: lib $(NAME)

lib		:
	make -C ./libft

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re:
	make fclean
	make all
