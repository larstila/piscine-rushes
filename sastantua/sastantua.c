/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkettune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:05:08 by lkettune          #+#    #+#             */
/*   Updated: 2020/02/10 09:58:48 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_writeline(int line, char tab[4], int spaces);
int		ft_countlines(int x);
int		ft_countwidth(int nb);

char	g_normal[4] = "/*\\";
int		g_floor = 1;
int		g_linewidth = 3;
int		g_nextfloorwidth = 6;
int		g_lastline = 3;
int		g_spaces = 0;
int		g_lastlinewidth = 7;

void	sastantua(int x)
{
	int line;

	g_spaces = (ft_countwidth(x) / 2 - 1);
	while (x >= g_floor)
	{
		line = 0;
		while (line < g_lastline)
		{
			ft_writeline(g_linewidth, g_normal, g_spaces);
			line++;
			g_spaces--;
			g_linewidth += 2;
		}
		g_linewidth += g_nextfloorwidth - 2;
		g_spaces -= (g_nextfloorwidth / 2 - 1);
		g_lastline++;
		if ((g_floor % 2) == 0)
		{
			printf("%d", g_nextfloorwidth);
			g_nextfloorwidth += 2;
		}
		g_floor++;
	}
}

void	ft_writeline(int linewidth, char tab[4], int spaces)
{
	int i;

	i = 0;
	while (i < spaces)
	{
		ft_putchar(' ');
		spaces--;
	}
	if (linewidth >= 1)
	{
		ft_putchar(tab[0]);
	}
	while (i < (linewidth - 2))
	{
		ft_putchar(tab[1]);
		i++;
	}
	if (linewidth >= 2)
	{
		ft_putchar(tab[2]);
	}
	ft_putchar('\n');
}

int		ft_countlines(int x)
{
	if (x >= 1)
	{
		x--;
		return (3 + x) + (ft_countlines(x));
	}
	return (0);
}

int		ft_countwidth(int x)
{
	int i;
	int width;
	int add;

	i = 1;
	width = 2;
	add = 4;
	while (i < x)
	{
		width += add;
		if (i % 2 == 0)
		{
			printf("%d", 0);
			add += 2;
		}
		i++;
	}
	width += (ft_countlines(x) * 2 - 2);
	printf("%d", width);
	return (width);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	sastantua(5);
	return (0);
}
