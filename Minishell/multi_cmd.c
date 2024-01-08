/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:00:06 by jooh              #+#    #+#             */
/*   Updated: 2023/12/11 21:08:58 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	check_what_cmd(tree, info)
{
	char	*path;

	if (strncmp(tree->cmd->simple_cmd, "env", 4) == 0)
		return (builtin_env(tree, info));
	else if (strncmp(tree->cmd->simple_cmd, "unset", 6) == 0)
		return (builtin_unset(tree, info));
	else if (strncmp(tree->cmd->simple_cmd, "export", 7) == 0)
		return (builtin_export(tree, info));
	else if (strncmp(tree->cmd->simple_cmd, "echo", 5) == 0)
		return (builtin_echo(tree, info));
	else if (strncmp(tree->cmd->simple_cmd, "cd", 3) == 0)
		return (builtin_cd(tree, info));
	else if (strncmp(tree->cmd->simple_cmd, "pwd", 4) == 0)
		return (builtin_pwd(tree, info));
	else if (strncmp(tree->cmd->simple_cmd, "exit", 5) == 0)
		return (builtin_exit(tree, info));
	else
	{
		path = cmd_path(info, cmd, 0);
		if (execve(path, cmd, info->envp) == -1)
			err_seq(cmd[0], 0, 126, 0);
		free(path);
	}
	return (0);
}

static void	first_child(tree, t_info *info)
{
	int		fd_read;

	fd_read = open_read_files(tree);
	dup2(fd_read);
	dup2((info->fd)[1]);
	close_pipe(info);
	exit(check_what_cmd(tree, info));
}

static void	last_child(tree, t_info *info)
{
	int		fd_write;

	fd_write = open_write_files(tree);
	dup2((info->fd)[(info->size * 2) - 4]);
	dup2(fd_write);
	close_pipe(info);
	exit(check_what_cmd(tree, info));
}

static void	other_childs(tree, t_info *info)
{
	int		*fd;

	fd = info->fd;
	dup2(fd[(info->idx) * 2 - 4]);
	dup2(fd[(info->idx) * 2 - 1]);
	close_pipe(info);
	exit(check_what_cmd(tree, info));
}

static void	child(tree, t_info *info)
{
	info->pid = fork();
	if (info->pid == 0)
	{
		if (info->idx == 1)
			first_child(tree, info);
		else if (info->idx == info->size)
			last_child(tree, info);
		else
			other_childs(tree, info);
	}
}
