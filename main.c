/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:35:43 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/20 18:47:34 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	lunch(t_for *ph)
{
	pthread_mutex_lock(&ph->next->forks[ph->r_fork]);
	ft_print_message(get_time() - ph->next->first_time,
		ph, " has taken a fork ");
	pthread_mutex_lock(&ph->next->forks[ph->l_fork]);
	ft_print_message(get_time() - ph->next->first_time,
		ph, " has taken a fork ");
	ft_print_message(get_time() - ph->next->first_time,
		ph, " is eating (^o^)");
	pthread_mutex_lock(ph->next->check_time);
	ph->last_eat = get_time();
	pthread_mutex_unlock(ph->next->check_time);
}

void	*routine(void *arg)
{
	t_for	*ph;

	ph = (t_for *)arg;
	if (ph->id % 2 != 0)
		usleep(100);
	while (1)
	{
		lunch(ph);
		pthread_mutex_lock(ph->next->print_v5);
		ph->next->n_eat++;
		pthread_mutex_unlock(ph->next->print_v5);
		ft_usleep(ph->next->t_eat);
		pthread_mutex_unlock(&ph->next->forks[ph->r_fork]);
		pthread_mutex_unlock(&ph->next->forks[ph->l_fork]);
		ft_print_message(get_time() - ph->next->first_time,
			ph, " is sleeping (~,~)");
		ft_usleep(ph->next->t_sleep);
		ft_print_message(get_time() - ph->next->first_time,
			ph, " is thinking (@_@)");
	}
	return (NULL);
}

void	mutex_init(t_philo *ph)
{
	int	i;

	i = 0;
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->n_philos);
	ph->print_check = malloc(sizeof(pthread_mutex_t));
	ph->print_v5 = malloc(sizeof(pthread_mutex_t));
	ph->check_time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(ph->check_time, NULL);
	pthread_mutex_init(ph->print_check, NULL);
	pthread_mutex_init(ph->print_v5, NULL);
	while (i < ph->n_philos)
	{
		pthread_mutex_init(&ph->forks[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_philo		*ph;
	pthread_t	*philo;

	ph = malloc(sizeof(t_philo));
	philo = malloc(sizeof(pthread_t) * ph->n_philos);
	if (ft_charck(ac, av, ph) == 0)
	{
		printf("ERROR\n");
		return (1);
	}
	mutex_init(ph);
	ph->first_time = get_time();
	t_fork(ph);
	i = 0;
	while (i < ph->n_philos)
	{
		ph->philos[i].last_eat = get_time();
		pthread_create(&philo[i], NULL, &routine, &ph->philos[i]);
		i++;
	}
	wax_mat(ph, ac);
	return (0);
}
