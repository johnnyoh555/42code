/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:39:56 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 16:53:33 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_same(t_stk *stka, t_stk *new)
{
	t_stk	*p;

	p = stka;
	while (p->next != stka)
	{
		if (p->nbr == new->nbr)
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
}
