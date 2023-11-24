/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:29:47 by jooh              #+#    #+#             */
/*   Updated: 2023/09/06 20:41:51 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	cnt;

	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (nb)
	{
		i = 1;
		cnt = 0;
		while (i * i <= nb && i * i > 0)
		{
			if (nb % i == 0)
				cnt++;
			if (cnt >= 2)
				break ;
			i++;
		}
		if (cnt == 1)
			break ;
		nb += 2;
	}
	return (nb);
}
