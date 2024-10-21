/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:26:06 by jooh              #+#    #+#             */
/*   Updated: 2023/08/30 15:20:52 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexa(unsigned char *str)
{
	char	arrc[2];
	int		arri[2];
	int		i;
	int		a;

	a = *str + 0;
	write(1, "\\", 1);
	arri[0] = a / 16;
	arri[1] = a % 16;
	i = 0;
	while (i <= 1)
	{
		if (arri[i] <= 9)
			arrc[i] = arri[i] + '0';
		else
			arrc[i] = arri[i] - 10 + 'a';
		i++;
	}
	write(1, arrc, 2);
	return ;
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if (*str < 32 || *str > 126)
			hexa((unsigned char *)str);
		else
			write(1, str, 1);
		str++;
	}
}
