/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:36:00 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 14:07:52 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	if_charset(char str, char *charset);

int	str_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str && if_charset(*str, charset) == 0)
	{
		str++;
		len++;
	}
	return (len);
}

int	if_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	countsize(char *str, char *charset)
{
	int	size;
	int	i;

	size = 0;
	while (*str)
	{
		while (*str && if_charset(*str, charset) == 1)
			str++;
		i = str_len(str, charset);
		str += i;
		if (i)
			size++;
	}
	return (size);
}

char	*str_cpy(char *str, int j)
{
	char	*arr2;
	int		i;

	i = 0;
	arr2 = (char *)malloc(sizeof(char) * (j + 1));
	if (arr2 == 0)
		return (0);
	while (i < j)
	{
		arr2[i] = str[i];
		i++;
	}
	arr2[i] = 0;
	return (arr2);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;
	int		i;
	int		j;

	size = countsize(str, charset);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*str && if_charset(*str, charset) == 1)
			str++;
		j = str_len(str, charset);
		arr[i] = str_cpy(str, j);
		str += j;
		i++;
	}
	arr[size] = 0;
	return (arr);
}
