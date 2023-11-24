/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:46:00 by jooh              #+#    #+#             */
/*   Updated: 2023/11/21 14:56:13 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr == 0)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	extension(t_info *info, int ac)
{
	unsigned int	i;

	if (ac == 1)
		return ;
	info->dn = 1;
	info->stkb = 0;
	check_sorted(info);
	i = -1;
	while (++i < info->size)
		change_nbr(info->stka, i);
	if (info->size < 6)
		hard_code(info);
	copy_stk(info->stka, &(info->stkc));
	start_sort(info);
	stkb_to_stka(info, 0);
	change_by_index(info);
	sort_print(info);
	stkb_to_stka(info, 1);
}
