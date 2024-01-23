/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:55 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/23 13:55:17 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_fract	fract;

	if (argc == 2 && (!ft_strncmp("mandelbrot", argv[1], 10)) || argc == 4 && !ft_strncmp("julia", argv[1], 5))
	{
		// INIT FRACT
		init(&fract);
		// RENDER
		render_fractal(&fract);
		// HOOKS
		create_hooks(&fract);
		// LOOP
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_putstr_fd("ERROR/INSTRUCTIONS\n", STDERR_FILENO); // TODO: give instructions
		exit(EXIT_FAILURE);
	}
	return (0);
}