/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:30:43 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 21:33:04 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	insert(int size, char **strs, char *sep, char *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		while (*strs[i] != 0)
		{
			*arr = *strs[i];
			arr++;
			strs[i]++;
		}
		j = 0;
		if (i != size - 1)
		{
			while (sep[j] != 0)
			{
				*arr = sep[j];
				arr++;
				j++;
			}
		}
		i++;
	}
	*arr = 0;
}

int	str_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != 0)
		i++;
	return (i);
}

int	strs_len(char *strs)
{
	int	i;

	i = 0;
	while (*strs != 0)
	{
		strs++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		strslen;
	int		i;

	i = 0;
	strslen = 0;
	while (i < size)
	{
		strslen += strs_len(strs[i]);
		i++;
	}
	strslen += str_len(sep) * (size - 1);
	if (size == 0)
		arr = (char *)malloc(sizeof(char) * 1);
	else
		arr = (char *)malloc(sizeof(char) * (strslen + 1));
	if (arr == 0)
		return (0);
	insert(size, strs, sep, arr);
	return (arr);
}
