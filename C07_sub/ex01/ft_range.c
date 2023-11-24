/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:16 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 18:30:18 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	j;

	if (min >= max)
		return (0);
	i = (max - min);
	arr = (int *)malloc(sizeof(int) * i);
	if (arr == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		arr[j] = min;
		j++;
		min++;
	}
	return (arr);
}
