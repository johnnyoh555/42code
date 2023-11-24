/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:22 by jooh              #+#    #+#             */
/*   Updated: 2023/10/16 17:17:35 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char *av[])
{
	int		fd;
	int		fd2;
	char	*str;
	char	*str2;

	if (ac != 3)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		str2 = get_next_line(fd2);
		printf("%s", str2);
		if (str == 0 && str2 == 0)
			break ;
		free(str2);
		free(str);
	}
	return (0);
}
