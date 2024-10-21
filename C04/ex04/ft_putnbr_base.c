/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:42:09 by jooh              #+#    #+#             */
/*   Updated: 2023/09/01 16:50:10 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	trans(int nbr, unsigned char *base, int base_len)
{
	int	i;

	if (nbr > 0)
	{
		trans(nbr / base_len, base, base_len);
		i = nbr % base_len;
		write(1, &base[i], 1);
	}
}

void	ft_1(int nbr, unsigned char *base, int base_len)
{
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		trans((nbr / base_len) * -1, base, base_len);
		trans(((-2147483648 % base_len) * -1), base, base_len);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	trans(nbr, base, base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;

	if (*base == 0 || *(base + 1) == 0)
		return ;
	i = 0;
	while (base[i] != 0)
	{	
		j = 0;
		while (base[j] != 0)
		{
			if (i != j && base[i] == base[j])
				return ;
			if (base[j] == '+' || base[j] == '-' || base[j] == ' ')
				return ;
			j++;
		}
		i++;
	}
	ft_1(nbr, (unsigned char *)base, i);
}
