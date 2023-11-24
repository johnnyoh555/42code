/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:23:43 by jooh              #+#    #+#             */
/*   Updated: 2023/09/09 21:29:08 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_change(char *tab[], int j)
{
	char	*temp;

	temp = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	a;

	a = 0;
	while (tab[a])
		a++;
	i = 0;
	while (i < a - 1)
	{
		j = 0;
		while (j < a - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_change(tab, j);
			j++;
		}
		i++;
	}
}
