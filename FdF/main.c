/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:29:41 by jooh              #+#    #+#             */
/*   Updated: 2023/11/24 13:21:25 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "FdF.h"

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 2)
		return (1);
	init_info(info, av[1]);

}





int	mlx(void)
{
	void	*mlx;
	void	*win;
	int 	color = 0x00ffffff;
	double 	c_x = 960;
	double	c_y = 540;
	double	r = 100;
	double	x;
	double	y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "hellow world!");

	x = c_x - r;
	while (x <= c_x + r)
	{
		y = c_y + sqrt(pow(r, 2) - pow(x - c_x, 2));
		mlx_pixel_put (mlx, win, x, y, color);
		y = c_y - sqrt(pow(r, 2) - pow(x - c_x, 2));
		mlx_pixel_put (mlx, win, x, y, color);
		x++;
	}
	y = c_y - r;
	while (y <= c_y + r)
	{
		x = c_x + sqrt(pow(r, 2) - pow(y - c_y, 2));
		mlx_pixel_put (mlx, win, x, y, color);
		x = c_x - sqrt(pow(r, 2) - pow(y - c_y, 2));
		mlx_pixel_put (mlx, win, x, y, color);
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
