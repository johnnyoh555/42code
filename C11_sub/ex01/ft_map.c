/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:47:57 by jooh              #+#    #+#             */
/*   Updated: 2023/09/09 21:26:45 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * length);
	if (arr == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		arr[i] = f(*tab);
		tab++;
		i++;
	}
	return (arr);
}
