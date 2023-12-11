/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:21:21 by jooh              #+#    #+#             */
/*   Updated: 2023/12/08 15:08:41 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	builtin_env(tree, info)
{
	int	i;

	i = 0;
	if (tree->argv[1] == 0)
	{
		while (info->envp[i])
		{
			if (ft_strchr(info->envp[i], '='))
				if (printf("%s\n", info->envp[i]) == -1)
					return (1);
		i++;
		}
	}
	else
	{
		printf("env: %s: No such file or directory", tree->argv[1]);
		return (1);
	}
	return (0);
}
