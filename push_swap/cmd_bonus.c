/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:30:23 by jooh              #+#    #+#             */
/*   Updated: 2023/11/17 19:53:33 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_sorted(t_info *info)
{
	t_stk			*p;

	p = info->stka;
	while (1)
	{
		if (p->nbr > (p->next)->nbr || info->stkb)
		{
			write(1, "KO\n", 3);
			del_stk(&(info->stka));
			del_stk(&(info->stkb));
			exit(1);
		}
		p = p->next;
		if (p->next == info->stka)
			break ;
	}
	write(1, "OK\n", 3);
	del_stk(&(info->stka));
	exit(0);
}

void	cmd_r(t_stk **stka, t_stk **stkb, int i)
{
	if (i == 0)
	{
		if (stka)
			if (*stka)
				*stka = (*stka)->next;
		if (stkb)
			if (*stkb)
				*stkb = (*stkb)->next;
	}
	else
	{
		if (stka)
			if (*stka)
				*stka = (*stka)->prev;
		if (stkb)
			if (*stkb)
				*stkb = (*stkb)->prev;
	}
}

void	cmd_p(t_stk **from, t_stk **to, t_stk *p)
{
	if (*from)
	{
		if ((*from)->next != *from)
		{
			((*from)->prev)->next = (*from)->next;
			((*from)->next)->prev = (*from)->prev;
			*from = (*from)->next;
		}
		else
			*from = 0;
		if (*to)
		{
			((*to)->prev)->next = p;
			p->next = *to;
			p->prev = (*to)->prev;
			(*to)->prev = p;
		}
		else
		{
			p->next = p;
			p->prev = p;
		}
		*to = p;
	}
}

void	cmd_s(t_stk *stka, t_stk *stkb)
{
	int				tmp_nbr;

	if (!(stka == 0 || stka->next == stka))
	{
		tmp_nbr = stka->nbr;
		stka->nbr = (stka->next)->nbr;
		(stka->next)->nbr = tmp_nbr;
	}
	if (!(stkb == 0 || stkb->next == stkb))
	{
		tmp_nbr = stkb->nbr;
		stkb->nbr = (stkb->next)->nbr;
		(stkb->next)->nbr = tmp_nbr;
	}
}

void	del_stk(t_stk **stk)
{
	t_stk	*p;

	if (stk == 0 || *stk == 0)
		return ;
	((*stk)->prev)->next = 0;
	while (*stk)
	{
		p = *stk;
		*stk = (*stk)->next;
		free(p);
	}
}
