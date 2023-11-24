/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:15:32 by jooh              #+#    #+#             */
/*   Updated: 2023/11/17 19:53:11 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_by_index(t_info *info)
{
	t_stk			*p;
	t_stk			*c;
	unsigned int	i;

	p = info->stka;
	i = -1;
	while (++i < info->size)
	{
		c = info->stkc;
		while (c->tnum != i)
			c = c->next;
		c->nbr = p->tnum;
		p = p->next;
	}
	info->stka = info->stkc;
	del_stk(&p);
	info->dn = 1;
}

void	copy_to_stkc(t_stk *new, t_stk **stkc)
{
	if (!(*stkc))
	{
		new->next = new;
		new->prev = new;
		*stkc = new;
	}
	else
	{
		new->next = *stkc;
		new->prev = (*stkc)->prev;
		(*stkc)->prev->next = new;
		(*stkc)->prev = new;
	}
}

void	copy_stk(t_stk *stka, t_stk **stkc)
{
	t_stk	*new;
	t_stk	*p;

	p = stka;
	*stkc = 0;
	while (1)
	{
		new = malloc(sizeof(t_stk));
		if (new == 0)
		{
			del_stk(&stka);
			del_stk(stkc);
			write(2, "ERROR\n", 6);
			exit(1);
		}
		new->nbr = p->nbr;
		new->tnum = p->tnum;
		copy_to_stkc(new, stkc);
		p = p->next;
		if (p == stka)
			break ;
	}
}

void	check_sorted(t_info *info)
{
	t_stk			*p;
	unsigned int	i;

	i = 0;
	p = info->stka;
	while (++i < info->size)
	{
		if (p->nbr > (p->next)->nbr)
			return ;
		p = p->next;
	}
	del_stk(&(info->stka));
	exit(0);
}

void	change_nbr(t_stk *stk, int i)
{
	t_stk	*p;
	t_stk	*min;

	p = stk;
	while (p->flag)
		p = p->next;
	min = p;
	while (1)
	{
		p = p->next;
		if (p == stk)
			break ;
		if (p->flag == 0 && p->nbr < min->nbr)
			min = p;
	}
	min->flag = 1;
	min->tnum = i;
}
