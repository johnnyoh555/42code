/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:47:55 by jooh              #+#    #+#             */
/*   Updated: 2023/11/22 16:48:50 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	wrong_cmd(t_info *info, char *str)
{
	write(2, "Error\n", 6);
	del_stk(&(info->stka));
	del_stk(&(info->stkb));
	free(str);
	exit(1);
}

void	use_cmd(t_info *info, char *str)
{
	if (!(ft_strncmp(str, "ra\n", 3)))
		cmd_r(&(info->stka), 0, 0);
	else if (!(ft_strncmp(str, "rb\n", 3)))
		cmd_r(&(info->stkb), 0, 0);
	else if (!(ft_strncmp(str, "rr\n", 3)))
		cmd_r(&(info->stka), &(info->stkb), 0);
	else if (!(ft_strncmp(str, "rra\n", 4)))
		cmd_r(&(info->stka), 0, 1);
	else if (!(ft_strncmp(str, "rrb\n", 4)))
		cmd_r(&(info->stkb), 0, 1);
	else if (!(ft_strncmp(str, "rrr\n", 4)))
		cmd_r(&(info->stka), &(info->stkb), 1);
	else if (!(ft_strncmp(str, "pa\n", 3)))
		cmd_p(&(info->stkb), &(info->stka), info->stkb);
	else if (!(ft_strncmp(str, "pb\n", 3)))
		cmd_p(&(info->stka), &(info->stkb), info->stka);
	else if (!(ft_strncmp(str, "sa\n", 3)))
		cmd_s(info->stka, 0);
	else if (!(ft_strncmp(str, "sb\n", 3)))
		cmd_s(info->stkb, 0);
	else if (!(ft_strncmp(str, "ss\n", 3)))
		cmd_s(info->stka, info->stkb);
	else
		wrong_cmd(info, str);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr == 0)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	reading(t_info *info)
{
	char	*str;

	info->stkb = 0;
	while (1)
	{
		str = get_next_line(0);
		if (str == 0)
			break ;
		use_cmd(info, str);
		free(str);
	}
	check_sorted(info);
}

int	main(int ac, char *av[])
{
	t_info	info;
	int		i;
	int		j;
	char	**arr;

	i = 0;
	info.stka = 0;
	while ((int)++i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (arr == 0 || arr[0] == 0)
		{
			write(2, "Error\n", 6);
			ft_free(arr);
			exit(1);
		}
		j = -1;
		while (arr[++j])
			add_to_stack(&(info.stka), arr[j]);
		ft_free(arr);
	}
	if (ac == 1)
		return (0);
	reading(&info);
	return (0);
}
