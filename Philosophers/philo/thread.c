/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:42 by jooh              #+#    #+#             */
/*   Updated: 2023/12/02 17:14:25 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	left_handed(t_info *info, t_philo *philo, int flag)
{
	while (flag)
	{
		usleep(100);
		if (time_go(info, philo, 0, 0))
			return ;
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		if (*(philo->real_r_fork) == 0 && *(philo->real_l_fork) == 0)
		{
			ft_printf(info, philo, "has taken a fork", 4);
			*(philo->real_l_fork) = 1;
			*(philo->real_r_fork) = 1;
			flag = 0;
		}
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	ft_printf(info, philo, "is eating", 0);
	time_go(info, philo, info->eat_time, 1);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	*(philo->real_l_fork) = 0;
	*(philo->real_r_fork) = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	right_handed(t_info *info, t_philo *philo, int flag)
{
	while (flag)
	{
		usleep(100);
		if (time_go(info, philo, 0, 0))
			return ;
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		if (*(philo->real_l_fork) == 0 && *(philo->real_r_fork) == 0)
		{
			ft_printf(info, philo, "has taken a fork", 4);
			*(philo->real_l_fork) = 1;
			*(philo->real_r_fork) = 1;
			flag = 0;
		}
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	ft_printf(info, philo, "is eating", 0);
	time_go(info, philo, info->eat_time, 1);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	*(philo->real_l_fork) = 0;
	*(philo->real_r_fork) = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*patern(void *lst)
{
	t_philo	*philo;

	philo = lst;
	philo->last_eat = get_time();
	if (philo->id % 2 == 1)
		usleep(300);
	while (1)
	{
		if (philo->id % 2 == 0)
			right_handed(philo->info, philo, 1);
		else
			left_handed(philo->info, philo, 1);
		if (philo->info->max_eat && philo->eat == philo->info->max_eat)
			break ;
		ft_printf(philo->info, philo, "is sleeping", 3);
		time_go(philo->info, philo, philo->info->slp_time, 0);
		ft_printf(philo->info, philo, "is thinking", 2);
		if (check_end(philo->info))
			break ;
		usleep(300);
	}
	return (0);
}

int	sitdown(t_info *info, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < info->humans)
	{
		if (pthread_create(philo[i].thread, 0, patern, &(philo[i])) != 0)
			return (THREADERR);
		i++;
	}
	i = 0;
	while (i < info->humans)
	{
		pthread_join(*(philo[i].thread), 0);
		i++;
	}
	return (0);
}
