/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:54:53 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/15 15:36:27 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		malloc_err();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (!fract->win)
	{
		mlx_destroy_window(fract->mlx, fract->win);
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
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_length, &fract->img.endian);
	add_data(fract);
}

int	main(int argc, char **argv)
{
	t_fract	fract;

	if (argc > 1 && (!ft_strncmp(argv[1], "mandelbrot", 10)
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
			|| !ft_strncmp(argv[1], "ship", 5)))
	{
		fract.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fract.julia_x = atod(argv[2]);
			fract.julia_y = atod(argv[3]);
		}
		else if (argc == 2 && !ft_strncmp(argv[1], "ship", 4))
			fract.is_ship = 1;
		else
			fract.is_ship = 0;
		init(&fract);
		render_fract(&fract);
		get_hooks(&fract);
		mlx_loop(fract.mlx);
	}
	else
		input_err();
	return (0);
}
