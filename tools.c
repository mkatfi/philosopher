/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:44:17 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/20 18:35:25 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;

	i = 0;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		nb = (str[i++] - 48) + nb * 10;
	if (ft_isalpha(str[i]))
		return (-1);
	return (nb);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_print_message(time_t i, t_for *p, char *str)
{
	pthread_mutex_lock(p->next->print_check);
	printf("%lu ms %d %s\n", i, p->id, str);
	pthread_mutex_unlock(p->next->print_check);
}

void	ft_usleep(long t)
{
	long	temp;

	temp = get_time();
	while (get_time() - temp < t)
	{
		usleep(100);
	}
}
