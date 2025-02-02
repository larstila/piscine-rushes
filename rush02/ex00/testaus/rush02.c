/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkettune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:26:43 by lkettune          #+#    #+#             */
/*   Updated: 2020/02/12 10:55:37 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_writeline(int x, char tab[3]);

char g_first[3] = "AB";
char g_middle[3] = "B ";
char g_last[3] = "CB";

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

void	ft_writeline(int x, char tab[3])
{
	int i;
	if (x <= 0)
	{
		return ;
	}
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
		ft_putchar(tab[0]);
	}
	ft_putchar('\n');
}
