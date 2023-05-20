/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:18:03 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/20 18:36:12 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<sys/time.h>
# include<pthread.h>

typedef struct s_for {
	int				id;
	int				l_fork;
	int				r_fork;
	long			last_eat;
	struct s_philo	*next;
}	t_for;

typedef struct s_philo {
	pthread_mutex_t	*forks;
	pthread_mutex_t	*check_time;
	pthread_mutex_t	*print_check;
	pthread_mutex_t	*print_v5;
	t_for			*philos;
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				n_philos;
	int				n_meal;
	int				n_eat;
	int				check;
	long			first_time;
}	t_philo;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_isalpha(int c);
void	ft_print_message(time_t i, t_for *p, char *str);
long	get_time(void);
int		ft_charck(int ac, char **av, t_philo *ph);
void	t_fork(t_philo *ph);
void	wax_mat(t_philo *ph, int ac);
void	ft_usleep(long t);
#endif