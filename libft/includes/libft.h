/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:57:01 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/18 17:40:27 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			string_length(const char *s);
char			*string_duplicate(const char *s);
char			*string_copy(char *dst, const char *src);
char			*string_copy_n(char *dst, const char *src, size_t len);
char			*string_cat(char *s1, const char *s2);
char			*string_cat_n(char *s1, const char *s2, size_t n);
size_t			string_cat_bound(char *dst, const char *src, size_t dstsize);
char			*string_find(const char *haystack, const char *needle);
char			*string_find_n(const char *haystack, const char *needle,
							size_t len);
int				string_compare(const char *s1, const char *s2);
int				string_compare_n(const char *s1, const char *s2, size_t n);
char			*string_find_char(const char *s, int c);
char			*string_find_char_last(const char *s, int c);
int				string_to_int(const char *str);
void			memory_clear(void *s, size_t n);

int				char_is_letter(int c);
int				char_is_uppercase(int c);
int				char_is_lowercase(int c);
int				char_is_digit(int c);
int				char_is_alphanumeric(int c);
int				char_is_ascii(int c);
int				char_is_printable(int c);
int				char_to_uppercase(int c);
int				char_to_lowercase(int c);

void			*memory_set(void *b, int c, size_t len);
void			*memory_find_char(const void *s, int c, size_t n);
void			*memory_move(void *dst, const void *src, size_t len);
void			*memory_copy(void *dst, const void *src, size_t len);
void			*memory_copy_until(void *dst, const void *src, int c,
									size_t len);
int				memory_compare(const void *s1, const void *s2, size_t n);

void			*memory_alloc(size_t size);
void			memory_delete(void **ap);
char			*string_new(size_t size);
void			string_delete(char **as);
void			string_clear(char *s);
void			string_iterate(char *s, void (*f)(char *));
void			string_iterate_i(char *s, void (*f)(unsigned int, char *));
char			*string_map(char const *s, char (*f)(char));
char			*string_map_i(char const *s, char (*f)(unsigned int, char));
int				string_equals(char const *s1, char const *s2);
int				string_equals_n(char const *s1, char const *s2, size_t n);
char			*string_sub(char const *s, unsigned int start, size_t len);
char			*string_join(char const *s1, char const *s2);
char			*string_trim_space(char const *s);
char			**string_split(char const *s, char c);
char			*int_to_string(int n);
void			print_char(char c);
void			print_string(char const *s);
void			print_endl(char const *s);
void			print_int(int n);
void			print_char_fd(char c, int fd);
void			print_string_fd(char const *s, int fd);
void			print_endl_fd(char const *s, int fd);
void			print_int_fd(int n, int fd);

t_list			*list_new(void const *content, size_t content_size);
void			list_delete_one(t_list **alst, void (*del)(void *, size_t));
void			list_delete(t_list **alst, void (*del)(void *, size_t));
void			list_push_front(t_list **alst, t_list *new);
void			list_iterate(t_list *lst, void (*f)(t_list *elem));
t_list			*list_map(t_list *lst, t_list *(*f)(t_list *elem));
void			list_push_back(t_list **alst, t_list *new);
int				list_length(t_list *lst);
t_list			*list_get_at(t_list *lst, unsigned int n);

#endif
