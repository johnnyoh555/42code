/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:57 by jooh              #+#    #+#             */
/*   Updated: 2023/11/26 22:20:18 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upperline(t_info *info, t_point *pi1, t_point *pi2, int minus)
{
	int	dx;
	int	dy;
	int	x1;
	int	y1;
	int	p;

	x1 = pi1->px;
	y1 = pi1->py;
	dx = (pi2->px - x1) * minus;
	dy = pi2->py - y1;
	p = (2 * dx) - dy;
	while (y1 <= pi2->py)
	{
		mlx_pixel_put (info->mlx, info->win, x1 + info->move_x,
			y1 + info->move_y, cha_color(pi1->color, pi2->color,
				(float)(y1 - pi1->py) / (float)(pi2->py - pi1->py)));
		y1++;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * (dx - dy);
			x1 += minus;
		}
	}
}

void	underline(t_info *info, t_point *pi1, t_point *pi2, int minus)
{
	int	dx;
	int	dy;
	int	x1;
	int	y1;
	int	p;

	x1 = pi1->px;
	y1 = pi1->py;
	dx = (pi2->px - x1);
	dy = (pi2->py - y1) * minus;
	p = (2 * dy) - dx;
	while (x1 <= pi2->px)
	{
		mlx_pixel_put(info->mlx, info->win, x1 + info->move_x,
			y1 + info->move_y, cha_color(pi1->color, pi2->color,
				(float)(x1 - pi1->px) / (float)(pi2->px - pi1->px)));
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * (dy - dx);
			y1 += minus;
		}
	}
}

void	bresenham(t_info *info, t_point *pi1, t_point *pi2)
{
	if (abs(pi2->px - pi1->px) > abs(pi2->py - pi1->py))
	{
		if ((pi1->px < pi2->px) && (pi1->py < pi2->py))
			underline(info, pi1, pi2, 1);
		else if ((pi1->px < pi2->px) && (pi1->py >= pi2->py))
			underline(info, pi1, pi2, -1);
		else if ((pi1->px >= pi2->px) && (pi1->py > pi2->py))
			underline(info, pi2, pi1, 1);
		else if ((pi1->px >= pi2->px) && (pi1->py <= pi2->py))
			underline(info, pi2, pi1, -1);
	}
	else
	{
		if ((pi1->py < pi2->py) && (pi1->px < pi2->px))
			upperline(info, pi1, pi2, 1);
		else if ((pi1->py < pi2->py) && (pi1->px >= pi2->px))
			upperline(info, pi1, pi2, -1);
		else if ((pi1->py >= pi2->py) && (pi1->px > pi2->px))
			upperline(info, pi2, pi1, 1);
		else if ((pi1->py >= pi2->py) && (pi1->px <= pi2->px))
			upperline(info, pi2, pi1, -1);
	}
}

void	drawline(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			if (i != info->max_y - 1)
				bresenham(info, (info->pi)[i][j], info->pi[i + 1][j]);
			if (j != info->max_x - 1)
				bresenham(info, (info->pi)[i][j], info->pi[i][j + 1]);
			j++;
		}
		i++;
	}
}
