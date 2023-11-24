/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:40:31 by jooh              #+#    #+#             */
/*   Updated: 2023/11/21 14:15:33 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(t_info *info, int in, int out)
{
	if (dup2(in, 0) == -1)
		ctl_error(info, 1, 0, "dup2");
	if (dup2(out, 1) == -1)
		ctl_error(info, 1, 0, "dup2");
}

void	freecmd(char **cmd)
{
	int	i;

	i = 0;
	if (cmd == 0)
		return ;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

int	quote_process(char *s)
{
	int		len;
	char	c;

	len = 1;
	c = *s;
	s++;
	while (*s && !(*s == c && *(s - 1) != '\\'))
	{
		s++;
		len++;
	}
	if (*s == c)
		len++;
	return (len);
}
