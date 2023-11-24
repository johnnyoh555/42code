/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:11:09 by jooh              #+#    #+#             */
/*   Updated: 2023/11/12 16:42:19 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by4_b(t_info *info)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i++ < info->size)
	{
		if ((info->stkb)->tnum / info->dn % 4 == 0)
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
		else if ((info->stkb)->tnum / info->dn % 4 == 1)
		{
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
			cmd_r(&(info->stka), 0, 0);
		}
		else if (++j)
			cmd_r(0, &(info->stkb), 0);
	}
	while (j-- > 0)
	{
		cmd_p(&(info->stkb), &(info->stka), info->stkb);
		if ((info->stka)->tnum / info->dn % 4 == 3)
			cmd_r(&(info->stka), 0, 0);
	}
}

void	sort_by4_a(t_info *info)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i++ < info->size)
	{
		if ((info->stka)->tnum / info->dn % 4 == 0)
			cmd_p(&(info->stka), &(info->stkb), info->stka);
		else if ((info->stka)->tnum / info->dn % 4 == 1)
		{
			cmd_p(&(info->stka), &(info->stkb), info->stka);
			cmd_r(0, &(info->stkb), 0);
		}
		else if (++j)
			cmd_r(&(info->stka), 0, 0);
	}
	while (j-- > 0)
	{
		cmd_p(&(info->stka), &(info->stkb), info->stka);
		if ((info->stkb)->tnum / info->dn % 4 == 3)
			cmd_r(0, &(info->stkb), 0);
	}
}

void	sort_by3_b(t_info *info)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i++ < info->size)
	{
		if ((info->stkb)->tnum / info->dn % 3 == 0)
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
		else if ((info->stkb)->tnum / info->dn % 3 == 1)
		{
			cmd_p(&(info->stkb), &(info->stka), info->stkb);
			cmd_r(&(info->stka), 0, 0);
		}
		else if ((info->stkb)->tnum / info->dn % 3 == 2)
		{
			cmd_r(0, &(info->stkb), 0);
			j++;
		}
	}
	while (j-- > 0)
		cmd_p(&(info->stkb), &(info->stka), info->stkb);
	info->dn *= 3;
	start_sort(info);
}

void	sort_by3_a(t_info *info)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i++ < info->size)
	{
		if ((info->stka)->tnum / info->dn % 3 == 0)
			cmd_p(&(info->stka), &(info->stkb), info->stka);
		else if ((info->stka)->tnum / info->dn % 3 == 1)
		{
			cmd_p(&(info->stka), &(info->stkb), info->stka);
			cmd_r(0, &(info->stkb), 0);
		}
		else if ((info->stka)->tnum / info->dn % 3 == 2)
		{
			cmd_r(&(info->stka), 0, 0);
			j++;
		}
	}
	while (j-- > 0)
		cmd_p(&(info->stka), &(info->stkb), info->stka);
	info->dn *= 3;
	start_sort(info);
}

void	start_sort(t_info *info)
{
	if (info->dn >= info->size)
		return ;
	if (info->size == 2)
	{
		write(1, "sa\n", 3);
		cmd_s(info->stka, 0);
		exit(0);
	}
	else if (info->dn * 3 < info->size && info->dn * 4 >= info->size)
	{
		if (info->stka == 0)
			sort_by4_b(info);
		else
			sort_by4_a(info);
	}
	else
	{
		if (info->stka == 0)
			sort_by3_b(info);
		else
			sort_by3_a(info);
	}
}
