/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:47:27 by jooh              #+#    #+#             */
/*   Updated: 2023/11/26 22:10:47 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fdf.h"

void	to_cen(t_info *info, t_point *f_p, t_point *l_p, int x)
{
	int	f_x;
	int	f_y;
	int	l_x;
	int	l_y;

	if (x == 0)
		x = 1;
	f_x = (f_p->x - f_p->y) * cos(info->mpi6) * info->dis;
	f_y = (f_p->x + f_p->y) * sin(info->mpi6) * info->dis - f_p->z * x;
	l_x = (l_p->x - l_p->y) * cos(info->mpi6) * info->dis;
	l_y = (l_p->x + l_p->y) * sin(info->mpi6) * info->dis - l_p->z * x;
	info->to_cen_x = 540 - ((l_x - f_x) / 2);
	info->to_cen_y = 360 - ((l_y - f_y) / 2);
}

void	calc_isometric(t_info *info, t_point *p)
{
	int	x;
	int	y;
	int	a;

	a = info->dis / 2;
	if (a == 0)
		a = 1;
	x = p->x;
	y = p->y;
	p->px = round((x - y) * cos(info->mpi6) * info->dis + info->to_cen_x);
	p->py = round((x + y) * sin(info->mpi6) * info->dis
			- p->z * a + info->to_cen_y);
}

void	isometric(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			calc_isometric(info, (info->pi)[i][j]);
			j++;
		}
		i++;
	}
}
