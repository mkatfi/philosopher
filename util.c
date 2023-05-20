/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:49:16 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/20 18:34:27 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	get_av(int ac, char **av, t_philo *ph)
{
	ph->n_philos = ft_atoi(av[1]);
	ph->t_die = ft_atoi(av[2]);
	ph->t_eat = ft_atoi(av[3]);
	ph->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		ph->n_meal = ft_atoi(av[5]);
}

int	ft_charck(int ac, char **av, t_philo *ph)
{
	if (ac == 5 || ac == 6)
	{
		get_av(ac, av, ph);
		if (ft_atoi(av[1]) == -1 || (ph->n_philos) <= 0)
			return (0);
		else if (ft_atoi(av[2]) == -1 || (ph->t_die) <= 0)
			return (0);
		else if (ft_atoi(av[3]) == -1 || (ph->t_eat) <= 0)
			return (0);
		else if (ft_atoi(av[4]) == -1 || (ph->t_sleep) <= 0)
			return (0);
		if (ac == 6)
		{
			if (ft_atoi(av[5]) == -1 || ph->n_meal <= 0)
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

void	t_fork(t_philo *ph)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ph->philos = malloc(sizeof(t_for) * ph->n_philos);
	while (i <= ph->n_philos)
	{
		if (i == ph->n_philos)
			ph->philos[j].l_fork = 0;
		else
			ph->philos[j].l_fork = i;
		ph->philos[j].r_fork = i - 1;
		ph->philos[j].id = i;
		ph->philos[j].next = ph;
		ph->n_eat = 0 ;
		i++;
		j++;
	}
}

void	wax_mat(t_philo *ph, int ac)
{
	int	i;

	while (1)
	{
		if (ac == 6)
		{
			pthread_mutex_lock(ph->print_v5);
			if (ph->n_philos * ph->n_meal == ph->n_eat)
				return ;
			pthread_mutex_unlock(ph->print_v5);
		}
		i = -1;
		while (++i < ph->n_philos)
		{
			pthread_mutex_lock(ph->check_time);
			if (get_time() - ph->philos[i].last_eat >= ph->t_die)
			{
				pthread_mutex_lock(ph->print_check);
				printf("%lu ms %d is death_note (*'*)\n",
					get_time() - ph->first_time, ph->philos[i].id);
				return ;
			}
			pthread_mutex_unlock(ph->check_time);
		}
	}
}
