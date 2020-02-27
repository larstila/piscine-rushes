/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforsstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:24:58 by jforsstr          #+#    #+#             */
/*   Updated: 2020/02/16 20:22:08 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	find_solution(int **grid, int i, int j)
{
	int x;

	x = 1;
	if (next_unassigned(grid, &i, &j) != 0)
	{
		return (1);
	}
	while (x <= 9)
	{
		if (find_value(grid, i, j, x) != 0)
		{
			x = find_value(grid, i, j, x);
			(grid)[i][j] = x;
			if (find_solution(grid, i, j) != 0)
			{
				return (1);
			}
			(grid)[i][j] = 0;
		}
		x++;
	}
	return (0);
}
