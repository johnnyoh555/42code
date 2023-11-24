/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:18:34 by jooh              #+#    #+#             */
/*   Updated: 2023/11/21 14:14:59 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size * 2 - 2)
	{
		if (close((info->fd)[i]) == -1)
			ctl_error(info, 1, 0, "close");
		i++;
	}
}

void	im_mario(t_info *info)
{
	int	*fd;
	int	i;

	fd = malloc(sizeof(int) * ((info->size * 2) - 2));
	if (fd == 0)
		ctl_error(info, 1, 0, "malloc");
	info->fd = fd;
	i = 0;
	while (i < ((info->size * 2) - 2))
	{
		if (pipe(fd + i) == -1)
			ctl_error(info, 1, 0, "pipe");
		i += 2;
	}
}

char	*str_cpy(t_info *info, char *s, int j, char *c)
{
	char	*arr2;
	char	*temp;

	arr2 = ft_calloc((j + 1), 1);
	if (arr2)
	{
		ft_memcpy(arr2, s, j);
		if (c)
		{
			temp = ft_slashbs(info, ft_strtrim(arr2, c));
			free(arr2);
			arr2 = temp;
		}
	}
	if (arr2 == 0)
		ctl_error(info, 1, 0, "malloc");
	return (arr2);
}

char	*ft_slashbs(t_info *info, char *str)
{
	char	*ret;
	int		i;
	int		j;

	ret = ft_calloc(ft_strlen(str) + 1, 1);
	i = 0;
	j = 0;
	while (str[j] && ret)
	{
		if (str[j] == '\\' && str[j + 1] == '\"')
			j++;
		ret[i] = str[j];
		j++;
		i++;
	}
	free(str);
	if (ret == 0)
		ctl_error(info, 1, 0, "malloc");
	return (ret);
}
