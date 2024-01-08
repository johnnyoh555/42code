/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:32:32 by jooh              #+#    #+#             */
/*   Updated: 2023/12/11 21:01:35 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	go_to_builtin(tree, info)
{
	if (strncmp(tree->cmd->simple_cmd, "env", 4) == 0)
		return (builtin_env(tree, info));
	if (strncmp(tree->cmd->simple_cmd, "unset", 6) == 0)
		return (builtin_unset(tree, info));
	if (strncmp(tree->cmd->simple_cmd, "export", 7) == 0)
		return (builtin_export(tree, info));
	if (strncmp(tree->cmd->simple_cmd, "echo", 5) == 0)
		return (builtin_echo(tree, info));
	if (strncmp(tree->cmd->simple_cmd, "cd", 3) == 0)
		return (builtin_cd(tree, info));
	if (strncmp(tree->cmd->simple_cmd, "pwd", 4) == 0)
		return (builtin_pwd(tree, info));
	if (strncmp(tree->cmd->simple_cmd, "exit", 5) == 0)
		return (builtin_exit(tree, info));
	return (0);
}

static int	single_builtin_cmd(tree, info)
{
	int		fd_read;
	int		fd_write;

	fd_read = open_read_files(tree);
	fd_write = open_write_files(tree);
	dup2(fd_read, 0);
	dup2(fd_write, 1);
	return (go_to_builtin(tree, info));
}

static int	single_simple_cmd(tree, info)
{
	int		fd_read;
	int		fd_write;
	char	*path;
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return (0);
	fd_read = open_read_files(tree);
	fd_write = open_write_files(tree);
	dup2(fd_read, 0);
	dup2(fd_write, 1);
	path = cmd_path(info, tree->cmd, 0);
	if (execve(path, tree->cmd, info->envp) == -1)
		err_seq(cmd[0], 0, 126, 0);
	free(path);
}

int	single_cmd(tree, info)
{
	if (strncmp(tree->cmd->simple_cmd, "env", 4) == 0
		|| strncmp(tree->cmd->simple_cmd, "unset", 6) == 0
		|| strncmp(tree->cmd->simple_cmd, "export", 7) == 0
		|| strncmp(tree->cmd->simple_cmd, "echo", 5) == 0
		|| strncmp(tree->cmd->simple_cmd, "cd", 3) == 0
		|| strncmp(tree->cmd->simple_cmd, "pwd", 4) == 0
		|| strncmp(tree->cmd->simple_cmd, "exit", 5) == 0)
		return (single_builtin_cmd(tree, info));
	else
		single_simple_cmd(tree, info);
	return (-1)
}

char	*cmd_path(t_info *info, char **cmd, int idx)
{
	char	*str;
	char	*ret;

	ret = ft_strdup(cmd[0]);
	if (ft_strchr(ret, '/') && access(ret, R_OK) == 0)
		return (ret);
	free(ret);
	if (ft_strchr(cmd[0], '/'))
		return (NULL);
	str = ft_strjoin("/", cmd[0]);
	while (info->path[idx])
	{
		ret = ft_strjoin((info->path)[idx], str);
		if (access(ret, R_OK) == 0)
			return (ret);
		free(ret);
		idx++;
	}
	free(str);
	err_seq(cmd[0], "command not found", 127, 0);
	return (0);
}
