/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:52:48 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/15 14:56:43 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	malloc_err(void)
{
	perror("Malloc error\n");
	exit(EXIT_FAILURE);
}

void	input_err(void)
{
	ft_putstr_fd("Please enter \"./fractol mandelbrot\"\n", STDERR_FILENO);
	ft_putstr_fd("or\t\"./fractol julia <value_1> ", STDERR_FILENO);
	ft_putstr_fd("<value_2>\"\nor\t\"./fractol ship\"", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	pixel_put(int x, int y, t_img *img, int colour)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = colour;
}

double	scale(double num, double new_min, double new_max, double old_max)
{
	double	result;
	double	divider;
	double	old_min;

	result = 0;
	old_min = 0;
	divider = (old_max - old_min);
	if (divider != 0)
		result = (new_max - new_min) * (num - old_min)
			/ (old_max - old_min) + new_min;
	return (result);
}

double	atod(char *str)
{
	double	pow;
	int		integer;
	double	decimal;
	int		sign;

	integer = 0;
	decimal = 0.0;
	sign = 1;
	pow = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str && *str != '.')
		integer = (integer * 10) + (*str++ - '0');
	if ('.' == *str)
		str++;
	while (*str)
	{
		pow /= 10;
		decimal = decimal + (*str++ - '0') * pow;
	}
	return ((integer + decimal) * sign);
}
