/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:52:58 by jooh              #+#    #+#             */
/*   Updated: 2023/09/10 20:39:17 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	rem(int a, int b);

void	puterror(char *c)
{
	if (*c == '/' && *(c + 1) == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (*c == '%' && *(c + 1) == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		write(1, "0\n", 2);
}

void	ft_toi(int nb)
{
	char	c;

	if (nb > 0)
	{
		ft_toi(nb / 10);
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		write(1, "\n", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return ;
	}
	ft_toi(nb);
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int			minus;
	int long	value;

	value = 0;
	minus = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	if (minus % 2 != 0)
		value *= -1;
	return ((int)value);
}

int	main(int ac, char *av[])
{
	int	(*ft[5])(int, int);

	ft[0] = add;
	ft[1] = sub;
	ft[2] = mul;
	ft[3] = div;
	ft[4] = rem;
	if (ac != 4)
		return (0);
	if (*av[2] == '+' && *(av[2] + 1) == 0)
		ft_putnbr(ft[0](ft_atoi(av[1]), ft_atoi(av[3])));
	else if (*av[2] == '-' && *(av[2] + 1) == 0)
		ft_putnbr(ft[1](ft_atoi(av[1]), ft_atoi(av[3])));
	else if (*av[2] == '*' && *(av[2] + 1) == 0)
		ft_putnbr(ft[2](ft_atoi(av[1]), ft_atoi(av[3])));
	else if (*av[2] == '/' && ft_atoi(av[3]) != 0 && *(av[2] + 1) == 0)
		ft_putnbr(ft[3](ft_atoi(av[1]), ft_atoi(av[3])));
	else if (*av[2] == '%' && ft_atoi(av[3]) != 0 && *(av[2] + 1) == 0)
		ft_putnbr(ft[4](ft_atoi(av[1]), ft_atoi(av[3])));
	else
		puterror(av[2]);
	return (0);
}
