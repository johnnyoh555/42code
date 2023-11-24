/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:07:28 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 20:44:35 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = max - min;
	range[0] = (int *)malloc(sizeof(int) * i);
	if (range[0] == 0)
		return (-1);
	j = 0;
	while (j < i)
	{
		range[0][j] = min;
		min++;
		j++;
	}
	return (i);
}
