/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:58:20 by aomman            #+#    #+#             */
/*   Updated: 2022/06/03 21:58:21 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include<unistd.h>
# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>

typedef struct s_var
{
	int				i;
	int				i2;
	int				j;
	int				num_philo;
	int				t_t_die;
	int				t_t_eat;
	int				t_t_sleep;
	int				number_eats;
	long			start_t;
	pthread_t		*th;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
}	t_var;

typedef struct s_data
{
	t_var	*var;
	int		times_eats;
	int		is_eat;
	int		s_eat;
	int		i;
}	t_data;

int		ft_atoi(char *str);
int		init_args(t_var *var, int argc, char **argv);
void	forks_philos(t_var *var, t_data *data);
void	init_data(t_var *var, t_data *data);
long	ft_gettime(long begin);
void	ft_usleep(int f_time);
void	*philo_death(t_data *data);

#endif