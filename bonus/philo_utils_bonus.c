/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:03:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/07/27 16:00:20 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = r * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (r * s);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&(time), NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	ft_time_diff(struct timeval time, long now)
{
	return (now - (time.tv_sec * 1000) - (time.tv_usec / 1000));
}

void	print_time(char *s, t_philo_data *data)
{
	long			t;

	t = get_time() - data->time;
	sem_wait(data->vars->print);
	printf("%ld	%d %s", t, data->x, s);
	sem_post(data->vars->print);
}

void	ft_usleep(int i)
{
	long	t;

	t = get_time();
	while (get_time() - t < (long)i)
		usleep(500);
}
