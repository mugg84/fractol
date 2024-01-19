/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:02:24 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/19 11:56:05 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		return ; //TODO: function to free
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "FRACT-OL");
	if (!fract->win)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_err();
	}
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_err();
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bits_per_pixel, &fract->img.line_len, &fract->img.endian);
	create_data(fract);
}

void	render_fractal(t_fract *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pxl(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
}

void	create_data(t_fract *fract)
{
	fract->escape_val = 4;
	fract->iteration_def = ITERATIONS;
	fract->zoom = 1;
	fract->move_x = 0;
	fract->move_y = 0;
}
