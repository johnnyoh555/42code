/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:48:23 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 13:20:52 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{	
	int	baselen;
	int	value;

	if (*str == 0)
		return (0);
	baselen = basecheck(base);
	if (baselen < 2)
		return (0);
	value = checkminus(str, base, baselen);
	return (value);
}
