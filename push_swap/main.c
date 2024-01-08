/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:34:28 by jooh              #+#    #+#             */
/*   Updated: 2023/12/12 17:22:25 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_size(char *str, int minus, int i)
{
	while (*str == '0')
		str++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ERROR);
		i++;
	}
	if (minus)
	{
		if (ft_strlen(str) > 10)
			return (ERROR);
		if (ft_strlen(str) == 10 && ft_strncmp(str, "2147483648", 10) > 0)
			return (ERROR);
	}
	else
	{
		if (ft_strlen(str) > 10)
			return (ERROR);
		if (ft_strlen(str) == 10 && ft_strncmp(str, "2147483647", 10) > 0)
			return (ERROR);
	}
	return (0);
}

int	check_rnbr(t_stk *stka, char *str)
{
	int	i;

	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i = 1;
		str++;
	}
	if (*str == 0 || check_size(str, i, 0))
	{
		write(2, "Error\n", 6);
		del_stk(&stka);
		exit(1);
	}
	return (0);
}

void	check_same(t_stk *stka, t_stk *nstk)
{
	t_stk	*p;

	p = stka;
	while (p->next != stka)
	{
		if (p->nbr == nstk->nbr)
		{
			write(2, "Error\n", 6);
			del_stk(&stka);
			exit(1);
		}
		p = p->next;
	}
}

void	add_to_stack(t_stk **stka, char *av)
{
	t_stk	*new;

	check_rnbr(*stka, av);
	new = malloc(sizeof(t_stk));
	if (new == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new->nbr = ft_atoi(av);
	if (!(*stka))
	{
		new->next = new;
		new->prev = new;
		*stka = new;
	}
	else
	{
		new->next = *stka;
		new->prev = (*stka)->prev;
		((*stka)->prev)->next = new;
		(*stka)->prev = new;
		check_same(*stka, new);
	}
	new->flag = 0;
}

int	main(int ac, char *av[])
{
	t_info	info;
	int		i;
	int		j;
	char	**arr;

	i = 0;
	info.size = 0;
	info.stka = 0;
	while ((int)++i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (arr == 0 || arr[0] == 0)
		{
			write(2, "Error\n", 6);
			ft_free(arr);
			exit(1);
		}
		j = -1;
		while (arr[++j] && ++info.size)
			add_to_stack(&(info.stka), arr[j]);
		ft_free(arr);
	}
	extension(&info, ac);
	return (0);
}
