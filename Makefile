# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:59:51 by apaulaus          #+#    #+#              #
#    Updated: 2018/11/29 16:00:39 by mdchane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRCS=main.c v2.c grid.c input.c result.c algorithm.c
OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror -I includes/ -I libft/includes/ -c $(SRCS)
	gcc -o $(NAME) $(OBJS) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -f *.o

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
