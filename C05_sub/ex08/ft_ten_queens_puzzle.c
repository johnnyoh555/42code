/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:45:00 by jooh              #+#    #+#             */
/*   Updated: 2023/09/04 23:07:16 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int arr[][10])
{	
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (arr[i][j] > 0)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	check(int arr[][10], int *count)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (arr[i][j] > 0)
				cnt++;
			j++;
		}
		i++;
	}
	if (cnt == 10)
	{
		count[0]++;
		print(arr);
	}
	return ;
}

void	change(int arr[][10], int i, int j, int a)
{
	int	b;

	b = 0;
	while (b < 10)
	{
		arr[i][b] += a;
		arr[b][j] += a;
		b++;
	}
	b = 1;
	while (i + b < 10 && j + b < 10)
	{
		arr[i + b][j + b] += a;
		b++;
	}
	b = 1;
	while (i + b < 10 && j - b >= 0)
	{
		arr[i + b][j - b] += a;
		b++;
	}
	return ;
}

void	dfs(int arr[][10], int i, int *count)
{
	int	j;

	if (i == 10)
	{
		check(arr, count);
		return ;
	}
	j = 0;
	while (j < 10)
	{
		if (arr[i][j] >= 0)
		{
			change(arr, i, j, -1);
			arr[i][j] = 1;
			dfs(arr, i + 1, count);
			change(arr, i, j, 1);
			arr[i][j] = 0;
		}
		j++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10][10];
	int	count[1];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	count[0] = 0;
	dfs(arr, 0, count);
	return (count[0]);
}
