/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:40:51 by jooh              #+#    #+#             */
/*   Updated: 2023/11/26 22:32:51 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_dis(t_info *info, int i)
{
	if (i == 27 && info->dis != 1)
		info->dis -= 1;
	else if (i == 24 && info->dis < 10)
		info->dis += 1;
	else
		return ;
	mlx_clear_window(info->mlx, info->win);
	to_cen(info, (info->pi)[0][0], (info->pi)[info->max_y - 1][info->max_x - 1],
		info->dis / 2);
	isometric(info);
	drawline(info);
}

void	move_point(t_info *info, int i)
{
	if (i == 13)
		info->move_y -= 10;
	if (i == 1)
		info->move_y += 10;
	if (i == 0)
		info->move_x -= 10;
	if (i == 2)
		info->move_x += 10;
	mlx_clear_window(info->mlx, info->win);
	drawline(info);
}

void	del_screen(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	write(1, "\e[32mGood by FdF\n\e[0m", 21);
	exit(0);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == 53)
		del_screen(info);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		move_point(info, keycode);
	if (keycode == 27 || keycode == 24)
		change_dis(info, keycode);
	return (0);
}

void	hooks(t_info *info)
{
	mlx_hook(info->win, 02, 0, key_press, info);
}

