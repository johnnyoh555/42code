/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:19:52 by jooh              #+#    #+#             */
/*   Updated: 2023/08/24 17:28:35 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	arr[2][2];
	int		a;
	int		b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			arr[0][0] = '0' + a / 10;
			arr[0][1] = '0' + a % 10;
			arr[1][0] = '0' + b / 10;
			arr[1][1] = '0' + b % 10;
			write (1, arr[0], 2);
			write (1, " ", 1);
			write (1, arr[1], 2);
			if (arr[0][0] == '9' && arr[0][1] == '8')
				break ;
			write (1, ", ", 2);
			b++;
		}
		a++;
	}
}
