/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:57:32 by jooh              #+#    #+#             */
/*   Updated: 2023/09/07 23:27:26 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	basecheck(char *base);

void	trans(int long nbr, char *base, char *arr, int j)
{	
	int	base_len;
	int	i;

	base_len = basecheck(base);
	if (nbr != 0)
	{
		trans(nbr / base_len, base, arr, j - 1);
		i = nbr % base_len;
		arr[j - 1] = base[i];
	}
}

void	to_char(int long nbr, char *base, char *arr, int j)
{
	if (nbr == 0)
	{
		arr[0] = base[0];
		arr[1] = 0;
		return ;
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		arr[0] = '-';
		arr[j] = 0;
		trans(nbr, base, arr, j);
	}
	else
	{
		arr[j] = 0;
		trans(nbr, base, arr, j);
	}
}

int	cntsize(int value, int tolen)
{
	int	i;

	i = 0;
	while (value != 0)
	{
		value /= tolen;
		i++;
	}
	return (i);
}
