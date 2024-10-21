/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:44 by jooh              #+#    #+#             */
/*   Updated: 2023/08/30 17:20:36 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_4(unsigned int size)
{
	unsigned int	i;

	i = 16 - size;
	while (i > 0)
	{
		write(1, "  ", 2);
		i--;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	ft_3(unsigned char *addr, unsigned int size)
{
	while (size > 0)
	{
		if (*addr < 32 || *addr > 126)
			write(1, ".", 1);
		else
			write(1, addr, 1);
		addr++;
		size--;
	}
	write(1, "\n", 1);
}

void	ft_2(unsigned char *addr, unsigned int size)
{
	char	c;
	int		a[2];
	int		b;
	int		i;

	i = 0;
	while (size-- > 0)
	{
		a[0] = (*addr + 0) / 16;
		a[1] = (*addr + 0) % 16;
		b = 0;
		while (b < 2)
		{	
			if (a[b] <= 9)
				c = a[b] + '0';
			else
				c = a[b] - 10 + 'a';
			write(1, &c, 1);
			b++;
		}
		i++;
		addr++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	ft_1(int long long addr, int i)
{
	char	c;

	if (i > 0)
	{
		i--;
		ft_1(addr / 16, i);
		if (addr == 0)
			write(1, "0", 1);
		else if (addr % 16 <= 9)
		{
			c = addr % 16 + '0';
			write(1, &c, 1);
		}
		else
		{
			c = addr % 16 - 10 + 'a';
			write(1, &c, 1);
		}
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	result;
	unsigned int	remain;

	result = size / 16;
	remain = size % 16;
	while (result > 0)
	{
		ft_1((int long long)addr, 16);
		write(1, ": ", 2);
		ft_2((unsigned char *)addr, 16);
		ft_3((unsigned char *)addr, 16);
		result--;
		addr += 16;
	}
	ft_1((int long long)addr, 16);
	write(1, ": ", 2);
	ft_2((unsigned char *)addr, remain);
	ft_4(remain);
	ft_3((unsigned char *)addr, remain);
	addr -= size - remain;
	return (addr);
}
