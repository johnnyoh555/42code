/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:05:08 by jooh              #+#    #+#             */
/*   Updated: 2023/09/10 23:49:41 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(int i)
{
	if (i == 0)
		return (0);
	else if (i < 0)
		return (-1);
	else
		return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	cmp;

	cmp = 0;
	i = 0;
	while (cmp == 0 && i < length - 1)
	{
		cmp = check(f(tab[i], tab[i + 1]));
		i++;
	}
	while (i < length - 1)
	{
		j = check(f(tab[i], tab[i + 1]));
		if (j != cmp && j != 0)
			return (0);
		i++;
	}
	return (1);
}
