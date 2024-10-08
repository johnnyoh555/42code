/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:57 by jooh              #+#    #+#             */
/*   Updated: 2023/12/11 16:25:40 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	wrong_exit_arg(info, char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	if (info->cmd == 1)
		ft_putstr_fd("exit\n", 2);
	exit(255);
}

static int	check_size(char *str, int minus, int idx)
{
	while (*str == '0')
		str++;
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (1);
		idx++;
	}
	if (minus)
	{
		if (ft_strlen(str) > 19)
			return (1);
		if (ft_strlen(str) == 19
			&& ft_strncmp(str, "9223372036854775808", 19) > 0)
			return (1);
	}
	else
	{
		if (ft_strlen(str) > 19)
			return (1);
		if (ft_strlen(str) == 19
			&& ft_strncmp(str, "9223372036854775807", 19) > 0)
			return (1);
	}
	return (0);
}

static long long	ft_atoll(char *str)
{
	int			minus;
	long long	value;

	value = 0;
	minus = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	if (*str == 0 || check_size(str, minus, 0))
		wrong_exit_arg(info, str);
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		if (value > 0 && minus == -1)
			value *= -1;
		value += *str - '0';
		str++;
	}
	return (value);
}

static void	right_exit(info, long long arg)
{
	long long	exit_num;

	exit_num = arg % 256;
	if (exit_num < 0)
		exit_num += 256;
	if (info->cmd == 1)
		ft_putstr_fd("exit\n", 2);
	exit(exit_num);
}

void	builtin_exit(tree, info)
{
	int	idx;

	idx = 1;
	if (tree->av[1] == 0)
	{
		if (info->cmd == 1)
			ft_putstr_fd("exit\n", 2);
		exit(0);
	}
	while (tree->av[idx])
	{
		ft_atoll(info, tree->av[idx]);
		idx++;
	}
	if (idx != 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		if (info->cmd == 1)
			ft_putstr_fd("exit\n", 2);
		exit(1);
	}
	right_exit(info, ft_atoll(info, tree->av[idx]));
}
