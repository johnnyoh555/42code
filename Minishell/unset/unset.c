/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:14:09 by jooh              #+#    #+#             */
/*   Updated: 2023/12/10 18:25:21 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	delete_env(info, char *arg)
{
	int		size;
	int		idx;
	char	**new_ev;
	int		i;
	int		len;

	len = ft_strlen(arg);
	size = 0;
	idx = -1;
	i = 0;
	while (info->envp[size])
		size++;
	new_ev = ft_calloc(sizeof(char *), (size));
	while (++idx < size - 1)
	{
		if (ft_strncmp(arg, info->envp[idx + i], len + 1))
		{
			free(info->envp[idx + i]);
			i = 1;
		}
		new_ev[idx] = ft_strdup(info->envp[idx + i]);
		free(info->envp[idx + i]);
	}
	free(info->envp);
	info->envp = new_ev;
}

static int	check_same_ev(char **envp, char *arg)
{
	int	len;
	int	idx;

	len = ft_strlen(arg);
	idx = 0;
	while (envp[idx])
	{
		if (ft_strncmp(envp[idx], arg, len) == 0
			&& (envp[idx][len] == '=' || envp[idx][len] == 0))
			return (1);
		idx++;
	}
	return (0);
}

static int	check_valid(char *arg)
{
	int	i;

	if (!(ft_isalpha(*arg) || *arg = '_'))
		return (1);
	i = 1;
	while (arg[i])
	{
		if (!(arg[i] == '_' || ft_isalnum(arg[i])))
			return (1);
		i++;
	}
	return (0);
}

static int	remove_ev(info, char *arg)
{
	if (*arg == '-' && *(arg + 1) == 0)
		return (0);
	if (check_valid(arg))
	{
		printf("minishell: unset: %s: not a valid identifier\n", arg);
		return (1);
	}
	if (check_same_ev(info->envp, arg))
		delete_env(info, arg);
	return (0);
}

int	builtin_unset(tree, info)
{
	int	idx;
	int	ret;

	ret = 0;
	if (tree->av[1] == 0)
		return (0);
	idx = 1;
	while (tree->av[idx])
	{
		if (remove_ev(info, tree->av[idx]))
			ret = 1;
		idx++;
	}
	return (ret);
}
