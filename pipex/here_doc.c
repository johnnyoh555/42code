/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:29:03 by jooh              #+#    #+#             */
/*   Updated: 2023/12/14 19:15:41 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	end_seq(t_info *info)
{
	int	i;

	i = -1;
	if (info->path)
	{
		while ((info->path)[++i])
			free((info->path)[i]);
		free(info->path);
	}
	free(info->fd);
	if (info->hd == 1)
	{
		unlink(info->flagfile);
		free(info->flagfile);
	}
}

void	checkfilename(t_info *info)
{
	char	*nbr;
	char	*fname;
	int		i;
	char	*str;

	fname = "./heredoc/heredoc_flag";
	i = 0;
	while (1)
	{
		nbr = ft_itoa(i);
		str = ft_strjoin(fname, nbr);
		free(nbr);
		if (access(str, F_OK) == -1)
		{
			info->flagfile = str;
			break ;
		}
		free(str);
		i++;
	}
}

void	make_hdfile(t_info *info)
{
	char	*str;
	int		fd;

	checkfilename(info);
	fd = open(info->flagfile, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ctl_error(info, 1, 0, info->flagfile);
	while (1)
	{
		str = get_next_line(0);
		if (str == 0)
			ctl_error(info, 1, 0, "malloc");
		if (ft_strlen(str) - 1 == ft_strlen((info->av)[2]))
			if (!ft_strncmp(str, (info->av)[2], ft_strlen((info->av)[2])))
				break ;
		write(fd, str, ft_strlen(str));
		free(str);
	}
	close(fd);
}

void	ctl_error(t_info *info, int i, int j, char *str)
{
	char	*err;

	if (info->hd == 1)
		unlink(info->flagfile);
	err = strerror(errno);
	if (j == 0)
	{
		write(2, "pipex: ", 7);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
	else if (j == 2)
	{
		write(2, "pipex: ", 7);
		write(2, str, ft_strlen(str));
		write(2, ": command not found\n", 20);
	}
	exit(i);
}
