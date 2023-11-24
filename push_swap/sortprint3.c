/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortprint3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:47:46 by jooh              #+#    #+#             */
/*   Updated: 2023/11/12 18:35:11 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_3b(t_info *info, unsigned int *i, int *j)
{
	write(1, "pa\n", 3);
	cmd_p(&(info->stkb), &(info->stka), info->stkb);
	if (*i != info->size && (info->stkb)->nbr / info->dn % 3 == 2)
	{
		write(1, "rr\n", 3);
		cmd_r(&(info->stka), &(info->stkb), 0);
		(*i)++;
		(*j)++;
	}
	else
	{
		write(1, "ra\n", 3);
		cmd_r(&(info->stka), 0, 0);
	}
}

void	sort_print3_b(t_info *info, unsigned int i, int j)
{
	while (i++ < info->size)
	{
		if ((info->stkb)->nbr / info->dn % 3 == 0)
		{
			write(1, "pa\n", 3);
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
		}
		else if ((info->stkb)->nbr / info->dn % 3 == 1)
			optimize_3b(info, &i, &j);
		else if ((info->stkb)->nbr / info->dn % 3 == 2)
		{
			write(1, "rb\n", 3);
			cmd_r(&(info->stkb), 0, 0);
			j++;
		}
	}
	while (j-- > 0)
	{
		write(1, "pa\n", 3);
		cmd_p(&(info->stkb), &(info->stka), info->stkb);
	}
	info->dn *= 3;
	sort_print(info);
}

void	optimize_3a(t_info *info, unsigned int *i, int *j)
{
	write(1, "pb\n", 3);
	cmd_p(&(info->stka), &(info->stkb), info->stka);
	if (*i != info->size && (info->stka)->nbr / info->dn % 3 == 2)
	{
		write(1, "rr\n", 3);
		cmd_r(&(info->stka), &(info->stkb), 0);
		(*i)++;
		(*j)++;
	}
	else
	{
		write(1, "rb\n", 3);
		cmd_r(0, &(info->stkb), 0);
	}
}

void	sort_print3_a(t_info *info, unsigned int i, int j)
{
	while (i++ < info->size)
	{
		if ((info->stka)->nbr / info->dn % 3 == 0)
		{
			write(1, "pb\n", 3);
			cmd_p(&(info->stka), &(info->stkb), info->stka);
		}
		else if ((info->stka)->nbr / info->dn % 3 == 2)
		{
			write(1, "ra\n", 3);
			cmd_r(&(info->stka), 0, 0);
			j++;
		}
		else if ((info->stka)->nbr / info->dn % 3 == 1)
			optimize_3a(info, &i, &j);
	}
	while (j-- > 0)
	{
		write(1, "pb\n", 3);
		cmd_p(&(info->stka), &(info->stkb), info->stka);
	}
	info->dn *= 3;
	sort_print(info);
}

void	sort_print(t_info *info)
{
	if (info->dn >= info->size)
		return ;
	else if (info->dn * 3 < info->size && info->dn * 4 >= info->size)
	{
		if (info->stka == 0)
			sort_print4_b(info, 0, 0);
		else
			sort_print4_a(info, 0, 0);
	}
	else
	{
		if (info->stka == 0)
			sort_print3_b(info, 0, 0);
		else
			sort_print3_a(info, 0, 0);
	}
}
