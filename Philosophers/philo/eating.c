/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:42:59 by jooh              #+#    #+#             */
/*   Updated: 2023/12/05 20:21:52 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_info *info, t_philo *philo)
{
	if (get_time() - philo->last_eat > info->die_time)
	{
		ft_printf(info, philo, "died", 1);
		return (1);
	}
	if (check_end(info))
		return (1);
	return (0);
}

void	time_to_eat(t_info *info, t_philo *philo)
{
	ft_printf(info, philo, "is eating", 0);
	time_go(info, philo, info->eat_time, 1);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	*(philo->real_r_fork) = 0;
	*(philo->real_l_fork) = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	usleep(100);
}

void	left_handed(t_info *info, t_philo *philo, int flag)
{
	while (flag == 1)
	{
		usleep(100);
		if (check_dead(info, philo))
			return ;
		pthread_mutex_lock(philo->l_fork);
		if (*(philo->real_l_fork) == 0)
		{
			pthread_mutex_lock(philo->r_fork);
			if (*(philo->real_r_fork) == 0)
			{
				if (check_dead(info, philo))
					return ;
				ft_printf(info, philo, "has taken a fork", 4);
				*(philo->real_l_fork) = 1;
				*(philo->real_r_fork) = 1;
				flag = 0;
			}
			pthread_mutex_unlock(philo->r_fork);
		}
		pthread_mutex_unlock(philo->l_fork);
	}
	usleep(100);
	time_to_eat(info, philo);
}

void	right_handed(t_info *info, t_philo *philo, int flag)
{
	while (flag == 1)
	{
		usleep(100);
		if (check_dead(info, philo))
			return ;
		pthread_mutex_lock(philo->r_fork);
		if (*(philo->real_r_fork) == 0)
		{
			pthread_mutex_lock(philo->l_fork);
			if (*(philo->real_l_fork) == 0)
			{
				if (check_dead(info, philo))
					return ;
				ft_printf(info, philo, "has taken a fork", 4);
				*(philo->real_l_fork) = 1;
				*(philo->real_r_fork) = 1;
				flag = 0;
			}
			pthread_mutex_unlock(philo->l_fork);
		}
		pthread_mutex_unlock(philo->r_fork);
	}
	usleep(100);
	time_to_eat(info, philo);
}
