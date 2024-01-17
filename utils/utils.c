/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:35 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/17 14:05:41 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_err(void)
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}

double	scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	double	result;

	result = (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
	return (result);
}

t_complex_num	calc_complex(t_complex_num *z, t_complex_num *c)
{
	double	temp;

	temp =  pow(z->real, 2) - pow(z->i, 2);
	z->i = 2 * z->real * z->i;
	z->real = temp;
	z->real += c->real;
	z->i += c->i;
}
