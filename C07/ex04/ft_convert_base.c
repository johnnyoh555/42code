/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:46:00 by jooh              #+#    #+#             */
/*   Updated: 2023/09/09 10:15:57 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		cntsize(int value, int tolen);
void	to_char(int long nbr, char *base, char *arr, int j);

int	checkstr(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	to_value(char *str, char *base, int baselen, int i)
{
	int long	value;
	int			a;

	value = 0;
	while (*str)
	{
		a = checkstr(*str, base);
		if (a == -1)
			break ;
		value *= baselen;
		value += a;
		str++;
	}
	value *= i;
	return ((int)value);
}

int	checkminus(char *str, char *base, int baselen)
{
	int	minus;
	int	value;

	minus = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	value = to_value(str, base, baselen, minus);
	return (value);
}

int	basecheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = 0;
		while (base[j] != 0)
		{
			if (i != j && base[i] == base[j])
				return (0);
			if (base[j] == '+' || base[j] == '-' || base[j] == ' '
				|| (base[j] >= 9 && base[j] <= 13))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{	
	char	*arr;
	int		fromlen;
	int		tolen;
	int		value;
	int		size;

	fromlen = basecheck(base_from);
	tolen = basecheck(base_to);
	if (fromlen < 2 || tolen < 2)
		return (0);
	value = checkminus(nbr, base_from, fromlen);
	size = cntsize(value, tolen);
	if (value <= 0)
		arr = (char *)malloc(sizeof(char) * size + 2);
	else
		arr = (char *)malloc(sizeof(char) * size + 1);
	if (arr == 0)
		return (0);
	if (value < 0)
		to_char((int long)value, base_to, arr, size + 1);
	else
		to_char((int long)value, base_to, arr, size);
	return (arr);
}
