/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:08:42 by aomman            #+#    #+#             */
/*   Updated: 2022/06/06 17:08:43 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philosophers.h"

void	new_philo(t_var *var, t_data *data, int id)
{
	pthread_mutex_lock(&var->mutex[id]);
	pthread_mutex_lock(&var->print);
	printf("%04ld %d has taken a fork\n", ft_gettime(var->start_t), id + 1);
	pthread_mutex_unlock(&var->print);
	id = (data->i + 1) % data->var->num_philo;
	pthread_mutex_lock(&var->mutex[id]);
	pthread_mutex_lock(&var->print);
	printf("%04ld %d has taken a fork\n", ft_gettime(var->start_t), data->i + 1);
	pthread_mutex_unlock(&var->print);
	data->s_eat = ft_gettime(var->start_t);
	data->is_eat = 1;
	pthread_mutex_lock(&var->print);
	printf("%04ld %d is eating\n", ft_gettime(var->start_t), data->i + 1);
	pthread_mutex_unlock(&var->print);
}

void	*routine(void *dt)
{
	t_data	*data;
	t_var	*var;
	int		id;

	data = (t_data *)dt;
	var = data->var;
	while (1)
	{
		id = data->i;
		new_philo(var, data, id);
		ft_usleep(var->t_t_eat * 1000);
		data->times_eats++;
		pthread_mutex_unlock(&var->mutex[data->i]);
		id = (data->i + 1) % data->var->num_philo;
		pthread_mutex_unlock(&var->mutex[id]);
		data->is_eat = 0;
		pthread_mutex_lock(&var->print);
		printf("%04ld %d is sleeping\n", ft_gettime(var->start_t), data->i + 1);
		pthread_mutex_unlock(&var->print);
		ft_usleep(var->t_t_sleep * 1000);
		pthread_mutex_lock(&var->print);
		printf("%04ld %d is thinking\n", ft_gettime(var->start_t), data->i + 1);
		pthread_mutex_unlock(&var->print);
	}
	return (NULL);
}

void	forks_philos(t_var *var, t_data *data)
{
	int	i;

	var->i = 0;
	while (var->i < var->num_philo)
	{
		pthread_mutex_init(&var->mutex[var->i], NULL);
		var->i++;
	}
	pthread_mutex_init(&var->print, NULL);
	i = 0;
	while (i < var->num_philo)
	{
		pthread_create(&var->th[i], NULL, &routine, &data[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < var->num_philo)
	{
		pthread_create(&var->th[i], NULL, &routine, &data[i]);
		i += 2;
	}
}
