/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:14:33 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 18:57:40 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	str_len(char *s)
{
	int	len;

	len = 0;
	if (*s == '\'' || *s == '\"')
		len = quote_process(s);
	else
	{
		while (*s && *s != ' ')
		{
			s++;
			len++;
		}
	}
	return (len);
}

static int	countsize(char *s)
{
	int	size;
	int	len;

	size = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		len = str_len(s);
		if (len && !((*s == '\'' || *s == '\"') && *(s + 1) == *s))
			size++;
		s += len;
	}
	return (size);
}

void	return_cmd(t_info *info, char *s, char **cmd, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		while (*s == ' ')
		{
			if ((*s == '\'' || *s == '\"') && *(s + 1) == *s)
				s += 2;
			else
				s++;
		}
		if (*s == '\'')
			cmd[i] = str_cpy(info, s, str_len(s), "\'");
		else if (*s == '\"')
			cmd[i] = str_cpy(info, s, str_len(s), "\"");
		else
			cmd[i] = str_cpy(info, s, str_len(s), 0);
		if (cmd[i] == 0)
			ctl_error(info, 1, 0, "malloc");
		s += str_len(s);
	}
}

char	**clean_up_cmd(t_info *info, char *s)
{
	char	**cmd;
	int		size;

	size = countsize(s);
	cmd = (char **)ft_calloc(size + 1, sizeof(char *));
	if (cmd == 0)
		ctl_error(info, 1, 0, "malloc");
	return_cmd(info, s, cmd, size);
	return (cmd);
}

char	*cmd_path(t_info *info, char **cmd, int i)
{
	char	*str;
	char	*ret;

	cmd[0] = ft_slashbs(info, cmd[0]);
	ret = ft_strdup(cmd[0]);
	if ((ft_strchr(ret, '/') && access(ret, R_OK) == 0) || info->path == 0)
		return (ret);
	free(ret);
	if (ft_strchr(cmd[0], '/'))
		return (NULL);
	str = ft_strjoin("/", cmd[0]);
	if (str == 0)
		ctl_error(info, 1, 0, "malloc");
	i = 0;
	while (info->path[i])
	{
		ret = ft_strjoin((info->path)[i], str);
		if (access(ret, R_OK) == 0)
			return (ret);
		free(ret);
		i++;
	}
	free(str);
	ctl_error(info, 127, 2, cmd[0]);
	return (0);
}
