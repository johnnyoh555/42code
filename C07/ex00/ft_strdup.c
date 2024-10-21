/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:32:09 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 18:37:54 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *src)
{	
	int	i;

	i = 0;
	while (*src != 0)
	{
		src++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*arr;
	int		s_len;
	int		i;

	s_len = str_len(src);
	arr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (arr == 0)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
