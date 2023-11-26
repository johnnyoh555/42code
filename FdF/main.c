/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:29:41 by jooh              #+#    #+#             */
/*   Updated: 2023/11/26 21:18:54 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fdf.h"

void	error_seq(t_info *info, char *str)
{
	info++;
	info--;
	str++;
	str--;
	exit(1);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 2)
		return (1);
	init_info(&info, av[1]);
	to_cen(&info, (info.pi)[0][0], (info.pi)[info.max_y - 1][info.max_x - 1],
		info.dis / 2);
	isometric(&info);
	drawline(&info);
	hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
