/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:05:06 by jooh              #+#    #+#             */
/*   Updated: 2023/09/05 15:32:55 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change(char *argv[], int j)
{
	char	*temp;

	temp = argv[j];
	argv[j] = argv[j + 1];
	argv[j + 1] = temp;
}

int	cmp(char *argv1, char *argv2)
{
	while (*argv1 != 0 || *argv2 != 0)
	{
		if (*argv1 != *argv2)
			break ;
		argv1++;
		argv2++;
	}
	return (*argv1 - *argv2);
}

void	sort(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i)
		{
			if (cmp(argv[j], argv[j + 1]) > 0)
				change(argv, j);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		sort (argc, argv);
		while (i < argc)
		{
			while (*argv[i] != 0)
			{
				write(1, argv[i], 1);
				argv[i]++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
	return (0);
}
