/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:47:50 by trahman           #+#    #+#             */
/*   Updated: 2020/02/16 19:43:16 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int search_box(int **grid, int i, int j, int x);
int search_axis(int **grid, int i_original, int j_original, int x);

int		find_value(int **grid, int i, int j, int x)
{
	int x_original;
	int a;

	while (x <= 9)
	{
		x_original = x;
		a = search_axis(grid, i, j, x);
		if (a == 0)
		{
			x++;
			continue ;
		}
		a = search_box(grid, i, j, x);
		if (a == 0)
		{
			x++;
			continue ;
		}
		if (x == x_original)
			return (x);
	}
	return (0);
}

int		search_box(int **grid, int i, int j, int x)
{
	int box_i;
	int box_j;

	box_i = ((i / 3) * 3);
	while (box_i < (((i / 3) * 3) + 3))
	{
		box_j = ((j / 3) * 3);
		while (box_j < ((j / 3) * 3 + 3))
		{
			if (grid[box_i][box_j] == x)
			{
				x++;
				return (0);
			}
			box_j++;
		}
		box_i++;
	}
	return (x);
}

int		search_axis(int **grid, int i_original, int j_original, int x)
{
	int j;
	int i;

	j = 0;
	while (j <= 8)
	{
		if (grid[i_original][j] == x)
		{
			x++;
			return (0);
		}
		j++;
	}
	i = 0;
	while (i <= 8)
	{
		if (grid[i][j_original] == x)
		{
			x++;
			return (0);
		}
		i++;
	}
	return (x);
}
