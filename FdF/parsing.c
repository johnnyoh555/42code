/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:04 by jooh              #+#    #+#             */
/*   Updated: 2023/11/24 13:58:07 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	check_y(t_info *info, char *mapname)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		error_seq(info, mapname);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	info->max_y = i;
	close(fd);
}

void	init_info(t_info *info, char *mapname)
{
	check_y(info, mapname);

}
