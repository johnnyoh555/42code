/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:43:33 by jooh              #+#    #+#             */
/*   Updated: 2023/08/27 12:06:08 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *arr, int cnt)
{
	while (cnt > 0)
	{
		write(1, &arr[10 - cnt], 1);
		cnt--;
	}
}

int	count(int a)
{
	int		cnt;

	cnt = 0;
	while (a != 0)
	{
		a /= 10;
		cnt++;
	}
	return (cnt);
}

void	ft_putnbr(int nb)
{
	char	arr[10];
	int		cnt;
	int		i;

	if (nb == 0)
		write(1, "0", 1);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	cnt = count(nb);
	i = 9;
	while (i >= 0)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	print(arr, cnt);
}
