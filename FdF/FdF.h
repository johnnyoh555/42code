/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:30 by jooh              #+#    #+#             */
/*   Updated: 2023/11/24 13:58:10 by jooh             ###   ########.fr       */
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

# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_info
{
	int		max_y;

	
}	t_info;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

#endif