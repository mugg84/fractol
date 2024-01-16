/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:55 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/16 14:29:16 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_err(void)
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_win(int keycode, t_fract *fract)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		exit(0); //TODO: get proper status/ check sigsegv err
	}
	return (0);
}

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
}

void	create_hooks(t_fract *fract)
{
		mlx_key_hook(fract->win, &close_win, &fract);
}

int	main(int argc, char *argv[])
{
	t_fract	fract;

	if (argc == 2 && (!ft_strncmp("mandelbrot", argv[1], 10) || !ft_strncmp("julia", argv[1], 5)))
	{
		// INIT FRACT
		init(&fract);
		// RENDER TODO: MORE EFFICIENT
		my_mlx_pixel_put(&fract.img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(fract.mlx, fract.win, fract.img.img, 5, 5);
		// HOOKS
		create_hooks(&fract);
		// LOOP
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_putstr_fd("ERROR/INSTRUCTIONS", STDERR_FILENO); // TODO: give instructions and exits properly
		exit(EXIT_FAILURE);
	}

	return (0);
}