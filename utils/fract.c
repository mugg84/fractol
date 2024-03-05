/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:54:44 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/15 15:22:19 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_fract_type(t_complex *z, t_complex *c, t_fract *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		c->real = fract->julia_x;
		c->i = fract->julia_y;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

void	add_data(t_fract *fract)
{
	fract->max_iter = ITERATIONS;
	fract->escape_val = 4;
	fract->zoom = 1;
	fract->move_x = 0.0;
	fract->move_y = 0.0;
}

t_complex	calc_complex(t_complex z, t_complex c, t_fract *fract)
{
	double	tmp;

	tmp = z.real;
	z.real = z.real * z.real - z.i * z.i + c.real;
	if (!fract->is_ship)
		z.i = 2 * tmp * z.i + c.i;
	else
		z.i = 2 * fabs(tmp * z.i) + c.i;
	return (z);
}

void	handle_pxl(int x, int y, t_fract *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	z.real = (scale(x, -2, 2, WIDTH) * fract->zoom) + fract->move_x;
	if (!fract->is_ship)
		z.i = (scale(y, 2, -2, HEIGHT) * fract->zoom) + fract->move_y;
	else
		z.i = (scale(y, -2, 2, HEIGHT) * fract->zoom) + fract->move_y;
	get_fract_type(&z, &c, fract);
	i = -1;
	while (++i < fract->max_iter)
	{
		z = calc_complex(z, c, fract);
		if (z.real * z.real + z.i * z.i > fract->escape_val)
		{
			colour = scale(i, BLACK, WHITE, fract->max_iter);
			pixel_put(x, y, &fract->img, colour);
			return ;
		}
	}
	pixel_put(x, y, &fract->img, WHITE);
}

void	render_fract(t_fract *fract)
{
	double	x;
	double	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			handle_pxl(x, y, fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
}
