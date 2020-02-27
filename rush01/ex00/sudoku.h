/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:40:34 by trahman           #+#    #+#             */
/*   Updated: 2020/02/16 22:04:58 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

int		find_solution(int **grid, int i, int j);
int		find_value(int **grid, int i, int j, int x);
int		is_done(int **grid);
int		**make_grid(int argc, char **argv, int **grid);
int		next_unassigned(int **grid, int *i, int *j);
void	write_grid(int **grid);

#endif
