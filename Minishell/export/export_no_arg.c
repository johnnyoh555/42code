/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:34:24 by jooh              #+#    #+#             */
/*   Updated: 2023/12/10 17:44:25 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



static char	*add_quotes(char *str)
{
	char	*ret;
	int		i;

	ret = ft_calloc(ft_strlen(str) + 3, 1);
	while (1)
	{
		ret[i] = str[i];
		if (ret[i] == '=')
			break ;
		i++;
	}
	ret[i + 1] = '"';
	i++;
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	ret[i + 1] = '"';
	free(str);
	return (ret);
}

static char	**ft_duprr(char **envp)
{
	char	**ret;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	ret = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (envp[i])
	{
		ret[i] = ft_dup(envp[i]);
		if (ft_strchr(ret[i], '='))
			ret[i] = add_quotes(ret[i]);
		i++;
	}
	return (ret);
}

static void	sort_by_ascii(char **envp, int size)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(envp[j], envp[j + 1]) > 0)
			{
				tmp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	show_evs(tree, info)
{
	char	**cpy_envp;
	int		i;

	cpy_envp = ft_duparr(info->envp);
	i = 0;
	while (info->envp[i])
		i++;
	sort_by_ascii(cpy_envp, i);
	add_quotes(cpy_envp);
	i = 0;
	while (cpy_envp[i])
	{
		printf("declare -x %s\n", cpy_envp[i]);
		i++;
	}
	i = 0;
	while (cpy_envp[i])
	{
		free(cpy_envp[i]);
		i++;
	}
	free(cpy_envp);
	return (0);
}

int	builtin_export(tree, info)
{
	int	idx;
	int	ret;

	ret = 0;
	if (tree->av[1] == 0)
	{
		show_evs(tree, info);
		return (0);
	}
	else
	{
		idx = 1;
		while (tree->av[idx])
		{
			if (make_ev(info, tree->av[idx]))
				ret = 1;
			idx++;
		}
	}
	return (ret);
}
