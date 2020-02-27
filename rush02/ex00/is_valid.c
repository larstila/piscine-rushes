/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkettune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:49:04 by lkettune          #+#    #+#             */
/*   Updated: 2020/02/23 21:57:26 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

int		is_valid(char **grid)
{
	int i;
	int j;
	int j_compare;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			j++;
		}
		if (i == 0)
			j_compare = j;
		if (j != j_compare)
			return (0);
		i++;
	}
	return (1);
}
