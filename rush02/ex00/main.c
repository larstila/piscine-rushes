/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:54:56 by esukava           #+#    #+#             */
/*   Updated: 2020/02/23 22:05:02 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

#define BUFFER_SIZE 15000

#include <fcntl.h>

t_input		*get_info(char **grid, t_input *info)
{
	if (!(info = malloc(sizeof(t_input))))
		return (info);
	info->d = dimensions(grid);
	info->grid = grid;
	return (info);
}

int			main(int argc, char **argv)
{
	char		*input;
	char		**grid;
	t_input		*info;
	int			ret;
	char		c;

	if ((input = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) < 0)
		return (1);
	ret = 0;
	while (read(0, &c, 1) > 0)
	{
		input[ret] = c;
		ret++;
	}
	input[ret] = '\0';
	grid = split(input);
	free(input);
	if (!is_valid(grid))
	{
		ft_putstr("aucune\n");
		return (0);
	}
	type(get_info(grid, info));
	return (0);
}
