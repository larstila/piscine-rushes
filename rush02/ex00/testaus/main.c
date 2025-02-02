/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:09:38 by ssalmi            #+#    #+#             */
/*   Updated: 2020/02/23 20:00:28 by lkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);


int		ft_atoi(char *str)
{
	int i;
	int sign;
	int ret;

	ret = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			sign = -1;
		}
		i++;
	}
	while (58 > str[i] && str[i] >= 48)
	{
		ret = (ret * 10) + str[i] - 48;
		i++;
	}
	return (ret * sign);
}



int	main(int argc, char **argv)
{
	
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}

