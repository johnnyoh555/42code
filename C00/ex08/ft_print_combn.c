/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:08:52 by jooh              #+#    #+#             */
/*   Updated: 2023/08/26 21:16:02 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first(char *arr, int n);

void	second(char *arr, int n, int a)
{
	if (arr[n - a - 1] == ('9' - a))
	{
		if (a > 0)
		{
			write(1, arr, n);
			write(1, ", ", 2);
		}
		arr[n - a - 2]++;
		a++;
		if (arr[0] == '9' - n + 1)
			first(arr, n);
		else if (a > 0)
			second(arr, n, a);
	}
	else if (arr[n - a - 1] != ('9' - a))
	{
		arr[n - a] = arr[n - a - 1] + 1;
		a--;
		if (a == 0)
			first(arr, n);
		else
			second(arr, n, a);
	}
}

void	first(char *arr, int n)
{
	write(1, arr, n);
	if (arr[0] == '9' - n + 1)
		return ;
	write(1, ", ", 2);
	if (arr[n - 1] != '9')
	{
		arr[n - 1]++;
		first(arr, n);
	}
	else if (arr[n - 1] == '9')
	{
		second(arr, n, 0);
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];
	int		a;

	a = 0;
	while (a < 9)
	{
		arr[a] = '0' + a;
		a++;
	}
	first(arr, n);
}
