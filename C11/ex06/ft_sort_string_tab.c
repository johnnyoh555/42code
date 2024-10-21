/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:02:26 by jooh              #+#    #+#             */
/*   Updated: 2023/09/09 21:16:54 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change(char *tab[], int j)
{
	char	*temp;

	temp = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = temp;
}

int	cmp(char *tab1, char *tab2)
{
	while (*tab1 != 0 || *tab2 != 0)
	{
		if (*tab1 != *tab2)
			break ;
		tab1++;
		tab2++;
	}
	return (*tab1 - *tab2);
}

void	sort(int a, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < a - 1)
	{
		j = 0;
		while (j < a - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				change(tab, j);
			j++;
		}
		i++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	a;

	a = 0;
	while (tab[a])
		a++;
	sort(a, tab);
}
