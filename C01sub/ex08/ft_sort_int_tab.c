/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:39:52 by jooh              #+#    #+#             */
/*   Updated: 2023/08/27 22:44:19 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	change(int *tab, int i)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	cnt;

	cnt = 0;
	while (cnt < size - 1)
	{
		cnt = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
				change(tab, i);
			else
				cnt++;
			i++;
		}
	}
}

/*int	main(void)
{
	int	tab[9] = {10, 9, 8, 12, 35, 22, 25, 11, 15};
	int	a = 0;

	ft_sort_int_tab(tab, 9);
	while (a < 9)
	{
		printf("%d ", tab[a]);
		a++;
	}
}*/
