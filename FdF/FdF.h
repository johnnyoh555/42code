/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:30 by jooh              #+#    #+#             */
/*   Updated: 2023/11/26 22:11:03 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		px;
	int		py;
	int		color;
}	t_point;

typedef struct s_info
{
	double	mpi6;
	int		max_y;
	int		max_x;
	int		dis;
	void	*mlx;
	void	*win;
	int		to_cen_x;
	int		to_cen_y;
	int		move_x;
	int		move_y;
	t_point	***pi;

}	t_info;

// main.c
void	error_seq(t_info *info, char *str);

// drawline.c
void	drawline(t_info *info);
void	bresenham(t_info *info, t_point *pi1, t_point *pi2);
void	underline(t_info *info, t_point *pi1, t_point *pi2, int minus);
void	upperline(t_info *info, t_point *pi1, t_point *pi2, int minus);

// convert.c
int		convert_base(char *str);
int		checkstr(char str, char *base);

// parsing.c
void	init_info(t_info *info, char *mapname);
void	check_y(t_info *info, char *mapname);
t_point	**check_x(t_info *info, int fd, int y);
t_point	*point_info(t_info *info, char *arr, int x, int y);
void	ft_free(char **arr);

// isometric.c
void	isometric(t_info *info);
void	calc_isometric(t_info *info, t_point *p);
void	to_cen(t_info *info, t_point *f_p, t_point *l_p, int x);

// colors.c
int		cha_color(int color1, int color2, float x);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// hooks.c
void	hooks(t_info *info);
int		key_press(int keycode, t_info *info);
void	del_screen(t_info *info);

#endif