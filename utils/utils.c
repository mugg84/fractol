/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:35 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/23 13:21:55 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_err(void)
{
	perror("Malloc error\n");
	exit(EXIT_FAILURE);
}

double	scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	double	result;
	double	divider;

	divider = (old_max - old_min);
	if (divider != 0)
		result = (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
	return (result);
}

void	calc_complex(t_complex_num *z, t_complex_num *c)
{
	//double z_real_sq = pow(z->real, 2);
	//double z_i_sq = pow(z->i, 2);
	double temp;

	if (!z || !c)
		return;
	temp = z->real * z->real - z->i * z->i;
	z->i = 2 * z->real * z->i;
	z->real = temp;
	z->real += c->real;
	z->i += c->i;
}
