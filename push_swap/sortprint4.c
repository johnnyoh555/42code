/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortprint4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:46:08 by jooh              #+#    #+#             */
/*   Updated: 2023/11/12 19:00:16 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_4b(t_info *info, unsigned int *i, int *j)
{
	write(1, "pa\n", 3);
	cmd_p(&(info->stkb), &(info->stka), info->stkb);
	if (*i != info->size && ((info->stkb)->nbr / info->dn % 4 == 2 \
		|| (info->stkb)->nbr / info->dn % 4 == 3))
	{
		(*i)++;
		(*j)++;
		write(1, "rr\n", 3);
		cmd_r(&(info->stka), &(info->stkb), 0);
	}
	else
	{
		write(1, "ra\n", 3);
		cmd_r(0, &(info->stka), 0);
	}
}

void	sort_print4_b(t_info *info, unsigned int i, int j)
{
	while (i++ < info->size)
	{
		if ((info->stkb)->nbr / info->dn % 4 == 0)
		{
			write(1, "pa\n", 3);
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
		}
		else if ((info->stkb)->nbr / info->dn % 4 == 1)
			optimize_4b(info, &i, &j);
		else if (++j)
		{
			write(1, "rb\n", 3);
			cmd_r(&(info->stkb), 0, 0);
		}
	}
	while (j-- > 0)
	{
		write(1, "pa\n", 3);
		cmd_p(&(info->stkb), &(info->stka), info->stkb);
		if ((info->stka)->nbr / info->dn % 4 == 3)
		{
			write(1, "ra\n", 3);
			cmd_r(0, &(info->stka), 0);
		}
	}
}

void	optimize_4a(t_info *info, unsigned int *i, int *j)
{
	write(1, "pb\n", 3);
	cmd_p(&(info->stka), &(info->stkb), info->stka);
	if (*i != info->size && (((info->stka)->nbr / info->dn % 4 == 2) \
		|| (info->stka)->nbr / info->dn % 4 == 3))
	{
		(*i)++;
		(*j)++;
		write(1, "rr\n", 3);
		cmd_r(&(info->stka), &(info->stkb), 0);
	}
	else
	{
		write(1, "rb\n", 3);
		cmd_r(0, &(info->stkb), 0);
	}
}

void	sort_print4_a(t_info *info, unsigned int i, int j)
{
	while (i++ < info->size)
	{
		if ((info->stka)->nbr / info->dn % 4 == 0)
		{
			write(1, "pb\n", 3);
			cmd_p(&(info->stka), &(info->stkb), info->stka);
		}
		else if ((info->stka)->nbr / info->dn % 4 == 1)
			optimize_4a(info, &i, &j);
		else if (++j)
		{
			write(1, "ra\n", 3);
			cmd_r(&(info->stka), 0, 0);
		}
	}
	while (j-- > 0)
	{
		write(1, "pb\n", 3);
		cmd_p(&(info->stka), &(info->stkb), info->stka);
		if ((info->stkb)->nbr / info->dn % 4 == 3)
		{
			write(1, "rb\n", 3);
			cmd_r(0, &(info->stkb), 0);
		}
	}
}
