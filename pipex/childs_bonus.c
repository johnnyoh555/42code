/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:25:28 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 14:24:11 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(t_info *info)
{
	int		fd;
	char	*path;
	char	**cmd;
	char	*str;

	if (info->hd)
		str = info->flagfile;
	else
		str = (info->av)[1];
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ctl_error(info, 1, 0, (str));
	ft_dup2(info, fd, (info->fd)[1]);
	close_pipe(info);
	cmd = clean_up_cmd(info, (info->av)[info->idx + 1 + info->hd]);
	path = cmd_path(info, cmd, 0);
	if (execve(path, cmd, info->envp) == -1)
		ctl_error(info, 126, 0, cmd[0]);
	free(path);
	freecmd(cmd);
}

void	last_child(t_info *info)
{
	int		fd;
	char	*path;
	char	**cmd;
	char	*name;

	name = (info->av)[info->size + 2 + info->hd];
	if (info->hd == 1)
		fd = open(name, O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		fd = open(name, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ctl_error(info, 1, 0, name);
	ft_dup2(info, (info->fd)[(info->size * 2) - 4], fd);
	close_pipe(info);
	cmd = clean_up_cmd(info, (info->av)[info->idx + 1 + info->hd]);
	path = cmd_path(info, cmd, 0);
	if (execve(path, cmd, info->envp) == -1)
		ctl_error(info, 126, 0, cmd[0]);
	free(path);
	freecmd(cmd);
}

void	other_childs(t_info *info)
{
	char	*path;
	char	**cmd;
	int		*fd;

	fd = info->fd;
	ft_dup2(info, fd[(info->idx) * 2 - 4], fd[(info->idx) * 2 - 1]);
	close_pipe(info);
	cmd = clean_up_cmd(info, (info->av)[info->idx + 1 + info->hd]);
	path = cmd_path(info, cmd, 0);
	if (execve(path, cmd, info->envp) == -1)
		ctl_error(info, 126, 0, cmd[0]);
	free(path);
	freecmd(cmd);
}

void	child(t_info *info)
{
	info->pid = fork();
	if (info->pid == 0)
	{
		if (info->idx == 1)
			first_child(info);
		else if (info->idx == info->size)
			last_child(info);
		else
			other_childs(info);
	}
}
