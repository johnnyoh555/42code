/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:23:36 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 18:40:20 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	info->path = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:", ':');
	while ((info->envp)[i] && info->path)
	{
		j = -1;
		if (!ft_strncmp("PATH=", (info->envp)[i], 5))
		{
			while ((info->path)[++j])
				free((info->path)[j]);
			free(info->path);
			info->path = ft_split((info->envp)[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (!(info->path))
		ctl_error(info, 1, 0, "malloc");
}

void	init_info(t_info *info, int ac, char *av[], char *envp[])
{
	info->av = av;
	info->envp = envp;
	info->idx = 0;
	info->hd = 0;
	if (!ft_strncmp("here_doc", av[1], 9))
	{
		info->hd = 1;
		make_hdfile(info);
	}
	info->size = ac - 3 - info->hd;
	find_path(info);
}

int	wait_dl(t_info *info)
{
	int		i;
	int		status;
	int		ret;

	i = 0;
	ret = 0;
	while (i < info->size)
	{
		if (wait(&status) == info->pid)
			if (WIFEXITED(status))
				ret = WEXITSTATUS(status);
		i++;
	}
	return (ret);
}

int	main(int ac, char *av[], char *envp[])
{
	t_info	info;
	int		ret;

	if (ac < 5 || (!ft_strncmp("here_doc", av[1], 8) && ac < 6))
		return (1);
	init_info(&info, ac, av, envp);
	im_mario(&info);
	while ((info.idx)++ < info.size)
		child(&info);
	close_pipe(&info);
	ret = wait_dl(&info);
	end_seq(&info);
	return (ret);
}
