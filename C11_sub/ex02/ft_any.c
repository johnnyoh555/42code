/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:53:02 by jooh              #+#    #+#             */
/*   Updated: 2023/09/09 21:27:10 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j += f(tab[i]);
		i++;
	}
	if (j == 0)
		return (0);
	return (1);
}
