/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforsstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:59:16 by jforsstr          #+#    #+#             */
/*   Updated: 2020/02/16 20:20:15 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	**make_grid(int argc, char **argv, int **grid)
{
	int x;
	int i;

	i = 0;
	while (i < argc - 1)
	{
		grid[i] = (int*)malloc(sizeof(int) * 9);
		x = 0;
		while (x <= 8)
		{
			if (argv[i + 1][x] != '.')
				grid[i][x] = argv[i + 1][x] - '0';
			if (argv[i + 1][x] == '.')
				grid[i][x] = 0;
			x++;
		}
		i++;
	}
	return (grid);
}
