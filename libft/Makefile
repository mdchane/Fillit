# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:59:51 by apaulaus          #+#    #+#              #
#    Updated: 2018/11/16 15:37:36 by apaulaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FILES=char_to_lowercase.c char_is_lowercase.c list_length.c memory_compare.c \
		print_char.c print_string_fd.c string_copy.c string_find_char.c \
		string_map.c char_to_uppercase.c char_is_printable.c list_map.c \
		memory_copy.c print_char_fd.c string_cat.c string_copy_n.c \
		string_find_char_last.c string_map_i.c int_to_string.c \
		char_is_uppercase.c list_new.c memory_copy_until.c print_endl.c \
		string_cat_bound.c string_delete.c string_find_n.c string_new.c \
		char_is_alphanumeric.c list_delete.c list_push_back.c memory_delete.c \
		print_endl_fd.c string_cat_n.c string_duplicate.c string_iterate.c \
		string_split.c char_is_ascii.c list_delete_one.c list_push_front.c \
		memory_find_char.c print_int.c string_clear.c string_equals.c \
		string_iterate_i.c string_sub.c char_is_digit.c list_get_at.c \
		memory_alloc.c memory_move.c print_int_fd.c string_compare.c \
		string_equals_n.c string_join.c string_to_int.c char_is_letter.c \
		list_iterate.c memory_clear.c memory_set.c print_string.c \
		string_compare_n.c string_find.c string_length.c string_trim_space.c \
		get_next_line.c
SRCS=$(FILES:%=srcs/%)
OBJS=$(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I includes -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
