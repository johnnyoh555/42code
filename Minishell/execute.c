/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:32:32 by jooh              #+#    #+#             */
/*   Updated: 2023/12/08 13:20:21 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_dup2(t_info *info, int in, int out)
{
	if (dup2(in, 0) == -1)
		ctl_error(info, 1, 0, "dup2");
	if (dup2(out, 1) == -1)
		ctl_error(info, 1, 0, "dup2");
}

int	single_simple_cmd(tree, info)
{
	int		fd_read;
	int		fd_write;
	char	*path;
	pid_t	pid;

	pid = fork;
	if (pid != 0)
		return (0);
	fd_read = open_read_files(tree);
	fd_write = open_write_files(tree);
	ft_dup2(fd_read, fd_write);
	close_pipe(info);
	path = cmd_path(info, tree->cmd, 0);
	if (execve(path, tree->cmd, info->envp) == -1)
		ctl_error(info, 126, 0, cmd[0]);
	free(path);
}

int	single_cmd(tree)
{
	if (strncmp(tree->cmd->simple_cmd, "env", 4) == 0);
	if (strncmp(tree->cmd->simple_cmd, "unset", 6) == 0);
	if (strncmp(tree->cmd->simple_cmd, "export", 7) == 0);
	if (strncmp(tree->cmd->simple_cmd, "echo", 5) == 0);
	if (strncmp(tree->cmd->simple_cmd, "cd", 3) == 0);
	if (strncmp(tree->cmd->simple_cmd, "pwd", 4) == 0);
	if (strncmp(tree->cmd->simple_cmd, "exit", 5) == 0);
	else
		single_simple_cmd();
}

int	execute(tree, info)
{
	if (info->pipes == 0)
		single_cmd(tree);
	
	int	i;

	i = 0;
	while (i <= info->pipes)
	{
		child(tree);
		tree = tree->next->pipe;
		i++;
	}
	
}
