/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkettune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:26:43 by lkettune          #+#    #+#             */
/*   Updated: 2020/02/09 12:11:20 by jforsstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_writeline(int x, char tab[4]);

char g_first[4] = "ABC";
char g_middle[4] = "B B";
char g_last[4] = "ABC";

void	rush(int x, int y)
{
	int i;

	if (y >= 1)
	{
		ft_writeline(x, g_first);
		i++;
	}
	while (i < (y - 1))
	{
		ft_writeline(x, g_middle);
		i++;
	}
	if (y >= 2)
	{
		ft_writeline(x, g_last);
	}
}

void	ft_writeline(int x, char tab[4])
{
	int i;

	i = 0;
	if (x >= 1)
	{
		ft_putchar(tab[0]);
		i++;
	}
	while (i < (x - 1))
	{
		ft_putchar(tab[1]);
		i++;
	}
	if (x >= 2)
	{
		ft_putchar(tab[2]);
	}
	ft_putchar('\n');
}
