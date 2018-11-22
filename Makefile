# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 08:36:51 by mdchane           #+#    #+#              #
#    Updated: 2018/11/22 14:18:43 by mdchane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = *.c

OBJS = $(SRCS:.c=.o)

HEADERS = .

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I $(HEADERS)
	gcc -o $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

