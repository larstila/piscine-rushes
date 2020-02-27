/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:08:36 by lstepany          #+#    #+#             */
/*   Updated: 2020/02/23 21:48:05 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_2_H
# define COLLE_2_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct			s_dimensions
{
	int					x;
	int					y;

}						t_dimensions;

typedef	struct			s_input
{
	t_dimensions		d;
	char				**grid;

}						t_input;

t_dimensions			dimensions(char **grid);
int						ft_col(char **grid, char **cmp, t_dimensions d);
void					ft_putchar(char c);
void					ft_putnbr(int nb);
void					ft_putstr(char *str);
void					ft_recognize(char **cmp,\
								char *collename, t_input *info, int *p);
int						ft_row(char *row, int x, char *cmp);
int						is_valid(char **grid);
char					**split(char *str);
void					type(t_input *info);

#endif
