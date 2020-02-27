/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:55:18 by esukava           #+#    #+#             */
/*   Updated: 2020/02/23 21:56:51 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

#define WHITESPACE(x) (x == '\t' || x == '\n' || x == '\0')

int		count_words(char *str)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!WHITESPACE(str[i]) && WHITESPACE(str[i + 1]))
			ret++;
		i++;
	}
	return (ret);
}

int		next_word_len(char *str, int k)
{
	int len;

	len = 0;
	while (WHITESPACE(str[k]))
		k++;
	while (!WHITESPACE(str[k]))
	{
		k++;
		len++;
	}
	return (len);
}

char	**split(char *str)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	k = 0;
	if ((ret = (char**)malloc(sizeof(*ret) * (count_words(str) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < count_words(str))
	{
		if ((ret[i] = (char*)malloc(next_word_len(str, k) + 1)) == NULL)
			return (NULL);
		j = 0;
		while (WHITESPACE(str[k]))
			k++;
		while (!WHITESPACE(str[k]))
		{
			ret[i][j++] = str[k++];
		}
		ret[i][j] = '\0';
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
