/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:17:06 by jooh              #+#    #+#             */
/*   Updated: 2023/11/12 16:13:08 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallcase(t_info *info)
{
	if (((info->stka)->tnum == 0 && ((info->stka)->next)->tnum == 2)
		|| ((info->stka)->tnum == 2 && ((info->stka)->next)->tnum == 1)
		|| ((info->stka)->tnum == 1 && ((info->stka)->next)->tnum == 0))
	{
		write(1, "sa\n", 3);
		cmd_s(info->stka, 0);
	}
	if ((info->stka)->tnum == 1)
	{
		write(1, "rra\n", 4);
		cmd_r(&(info->stka), 0, 1);
	}
	if ((info->stka)->tnum == 2)
	{
		write(1, "ra\n", 3);
		cmd_r(&(info->stka), 0, 0);
	}
}

void	push_max4(t_info *info, t_stk *p)
{
	int		i;

	i = 0;
	while (p->tnum != 3)
	{
		p = p->next;
		i++;
	}
	if (i == 3)
	{
		write (1, "rra\n", 4);
		cmd_r(&(info->stka), 0, 1);
	}
	else
	{
		while (i-- > 0)
		{
			write(1, "ra\n", 3);
			cmd_r(&(info->stka), 0, 0);
		}
	}
}

void	push_max5(t_info *info, t_stk *p)
{
	int		i;

	i = 0;
	while (p->tnum != 4)
	{
		i++;
		p = p->next;
	}
	if (i >= 3)
	{
		while (5 - i > 0)
		{
			write (1, "rra\n", 4);
			cmd_r(&(info->stka), 0, 1);
			i++;
		}
	}
	else
	{
		while (i-- > 0)
		{
			write(1, "ra\n", 3);
			cmd_r(&(info->stka), 0, 0);
		}
	}
}

void	hard_code(t_info *info)
{
	if (info->size == 5)
	{
		push_max5(info, info->stka);
		write(1, "pb\n", 3);
		cmd_p(&(info->stka), &(info->stkb), info->stka);
	}
	if (info->size >= 4)
	{
		push_max4(info, info->stka);
		write(1, "pb\n", 3);
		cmd_p(&(info->stka), &(info->stkb), info->stka);
	}
	smallcase(info);
	while (info->stkb)
	{
		write(1, "pa\n", 3);
		write(1, "ra\n", 3);
		cmd_p(&(info->stkb), &(info->stka), info->stkb);
		cmd_r(&(info->stka), 0, 0);
	}
	del_stk(&(info->stka));
	exit(0);
}
