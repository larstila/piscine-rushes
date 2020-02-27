/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:54:34 by esukava           #+#    #+#             */
/*   Updated: 2020/02/23 21:56:11 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

t_dimensions	dimensions(char **grid)
{
	t_dimensions	d;
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (grid[y] != NULL)
	{
		y++;
	}
	while (grid[0][x] != '\0')
	{
		x++;
	}
	d.x = x;
	d.y = y;
	return (d);
}
