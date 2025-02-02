/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkettune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:47:07 by lkettune          #+#    #+#             */
/*   Updated: 2020/02/23 22:09:56 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

int		ft_row(char *row, int x, char *cmp)
{
	int i;

	i = 0;
	if (x <= 0)
	{
		return (0);
	}
	if (x >= 1)
	{
		if (!(row[i] == cmp[0]))
			return (0);
		i++;
	}
	while (i < (x - 1))
	{
		if (!(row[i] == cmp[1]))
			return (0);
		i++;
	}
	if (x >= 2)
	{
		if (!(row[i] == cmp[2]))
			return (0);
	}
	return (1);
}

int		ft_col(char **grid, char **cmp, t_dimensions d)
{
	int i;

	i = 0;
	if (d.y >= 1)
	{
		if (!(ft_row(grid[i], d.x, cmp[0])))
			return (0);
		i++;
	}
	while (i < (d.y - 1))
	{
		if (!(ft_row(grid[i], d.x, cmp[1])))
			return (0);
		i++;
	}
	if (d.y >= 2)
	{
		if (!(ft_row(grid[i], d.x, cmp[2])))
			return (0);
	}
	return (1);
}

void	ft_recognize(char **cmp, char *collename, t_input *info, int *p)
{
	if (ft_col(info->grid, cmp, info->d))
	{
		write(1, "[", 1);
		ft_putstr(collename);
		ft_putstr("] [");
		ft_putnbr((info->d.x));
		ft_putstr("] [");
		ft_putnbr((info->d.y));
		write(1, "]", 1);
		*p = 1;
	}
}

void	type(t_input *info)
{
	int			p;

	p = 0;
	if (info->grid[0][0] == 'o')
		ft_recognize((char *[]){"o-o", "| |", "o-o"}, "rush-00", info, &p);
	if (info->grid[0][0] == '/')
		ft_recognize((char *[]){"/*\\", "* *", "\\*/"}, "rush-01", info, &p);
	if (info->grid[0][0] == 'A')
		ft_recognize((char *[]){"ABA", "B B", "CBC"}, "colle-02", info, &p);
	if (info->grid[0][0] == 'A')
	{
		if (p && ft_col(info->grid, (char *[]){"ABC", "B B", "ABC"}, info->d))
			ft_putstr(" || ");
		ft_recognize((char *[]){"ABC", "B B", "ABC"}, "colle-03", info, &p);
	}
	if (info->grid[0][0] == 'A')
	{
		if (p && ft_col(info->grid, (char *[]){"ABC", "B B", "CBA"}, info->d))
			ft_putstr(" || ");
		ft_recognize((char *[]){"ABC", "B B", "CBA"}, "colle-04", info, &p);
	}
	if (!p)
		ft_putstr("aucune\n");
	else
		ft_putstr("\n");
}
