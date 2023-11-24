/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:46 by jooh              #+#    #+#             */
/*   Updated: 2023/11/12 20:30:43 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_r(t_stk **stka, t_stk **stkb, int i)
{
	if (i == 0)
	{
		if (stka)
			*stka = (*stka)->next;
		if (stkb)
			*stkb = (*stkb)->next;
	}
	else
	{
		if (stka)
			*stka = (*stka)->prev;
		if (stkb)
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
	unsigned int	tmp_num;
	int				tmp_nbr;

	if (!(stka == 0 || stka->next == stka))
	{
		tmp_nbr = stka->nbr;
		tmp_num = stka->tnum;
		stka->nbr = (stka->next)->nbr;
		stka->tnum = (stka->next)->tnum;
		(stka->next)->nbr = tmp_nbr;
		(stka->next)->tnum = tmp_num;
	}
	if (!(stkb == 0 || stkb->next == stkb))
	{
		tmp_nbr = stkb->nbr;
		tmp_num = stkb->tnum;
		stkb->nbr = (stkb->next)->nbr;
		stkb->tnum = (stkb->next)->tnum;
		(stkb->next)->nbr = tmp_nbr;
		(stkb->next)->tnum = tmp_num;
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

void	stkb_to_stka(t_info *info, int i)
{
	if (!i)
	{
		while (info->stkb)
		{
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
			cmd_r(&(info->stka), 0, 0);
		}
	}
	else
	{
		while (info->stkb)
		{
			write(1, "pa\n", 3);
			write(1, "ra\n", 3);
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
			cmd_r(&(info->stka), 0, 0);
		}
		del_stk(&(info->stka));
	}
}
