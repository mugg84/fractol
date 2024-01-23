/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:04:30 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/23 13:23:41 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pxl(int x, int y, t_img *img, int colour)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = colour;
}

void	handle_pxl(int x, int y, t_fract *fract)
{
	t_complex_num	*z;
	t_complex_num	*c;
	int				i;
	int				colour;

	z = (t_complex_num *)malloc(sizeof(t_complex_num));
	c = (t_complex_num *)malloc(sizeof(t_complex_num));
	if (z == NULL || c == NULL)
	{
		free(z);
		free(c);
		malloc_err();
		return ;
	}
	z->real = 0.0;
	z->i = 0.0;
	// c->real = (scale(x, -2, 2, 0, WIDTH) + fract->move_x) * fract->zoom;
	// c->i = (scale(y, 2, -2, 0, HEIGHT) + fract->move_y) * fract->zoom;
	c->real = (scale(x, -2, 2, 0, WIDTH) * fract->zoom) + fract->move_x;
	c->i = (scale(y, 2, -2, 0, HEIGHT) * fract->zoom) + fract->move_y;
	calc_complex(z, c);
	i = -1;
	while (++i < fract->iteration_def)
	{
		if ((z->real * z->real) + (z->i * z->i) > fract->escape_val)
		{
			colour = scale(i, BLACK, WHITE, 0, fract->iteration_def);
			put_pxl(x, y, &fract->img, colour);
			free(z);
			free(c);
			return ;
		}
		calc_complex(z, c);
	}
	put_pxl(x, y, &fract->img, BLACK);
	free(z);
	free(c);
}