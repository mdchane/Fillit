/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:59:28 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/18 17:16:35 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

# include "libft.h"

typedef struct	s_v2
{
	int x;
	int y;
}				t_v2;

typedef struct	s_tetromino
{
	int		piece_count;
	t_v2	pieces[4];
}				t_tetromino;

int				abs(int num);

t_v2			v2(int x, int y);
t_v2			add(t_v2 a, t_v2 b);
t_v2			sub(t_v2 a, t_v2 b);
int				equal(t_v2 a, t_v2 b);
int				touch(t_v2 a, t_v2 b);

void			grid_set(t_v2 pos, char c, char *grid, int size);
char			grid_get(t_v2 pos, char *grid, int size);
int				inside_grid(t_v2 pos, int size);
int				check_place(t_tetromino *tet, t_v2 pos, char *grid, int size);

void			error();
void			print_result(char *grid, int size);

t_list			*read_tetrominoes(char *filename);

void			run_algorithm(t_list *head, char **grid, int *size);

#endif
