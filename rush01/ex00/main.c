/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkettune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 11:58:07 by lkettune          #+#    #+#             */
/*   Updated: 2020/02/16 21:57:23 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		valid(int argc, char **argv);
int		clues(int argc, char **argv);

int		main(int argc, char **argv)
{
	int **grid;
	int x;
	int solutions;
	int i;
	int j;

	solutions = 0;
	if (!(argc == 10 && valid(argc, argv)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	grid = (int**)malloc(sizeof(int*) * 9);
	grid = make_grid(argc, argv, grid);
	i = 0;
	j = 0;
	x = 1;
	find_solution(grid, i, j);
	if (is_done(grid) == 1)
		write_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}

int		valid(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= 49 && argv[i][j] <= 57) || argv[i][j] == '.'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	if (clues(argc, argv) < 17)
		return (0);
	return (1);
}

int		clues(int argc, char **argv)
{
	int i;
	int j;
	int clues;

	i = 1;
	clues = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= 49 && argv[i][j] <= 57)
				clues++;
			j++;
		}
		i++;
	}
	return (clues);
}
