/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:55 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/17 14:05:36 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_fract	fract;

	if (argc == 2 && (!ft_strncmp("mandelbrot", argv[1], 10) || !ft_strncmp("julia", argv[1], 5)))
	{
		// INIT FRACT
		init(&fract);
		// RENDER TODO: MORE EFFICIENT
		render_fractal(&fract);
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