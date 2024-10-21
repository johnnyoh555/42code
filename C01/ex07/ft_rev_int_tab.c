/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:28:33 by jooh              #+#    #+#             */
/*   Updated: 2023/08/27 22:43:32 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

/*int	main(void)
{
	int tab[4] = {10, 9, 43, 45};
	int i;

	i = 0;
	ft_rev_int_tab(tab, 4);
	while (i < 4)
	{
		printf("%d ", tab[i]);
		i++;
	}
}*/
