/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:53 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/18 12:56:51 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_win(t_fract *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->win);
	free(fract->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_key(int keycode, t_fract *fract)
{
	if (keycode == XK_Escape)
		close_win(fract);
	return (0);
}

int	handle_mouse(int mouse_btn, int x, int y, t_fract *fract)
{
	if (mouse_btn == 4)
		fract->zoom *= 1.05;
	else if (mouse_btn == 5)
		fract->zoom *= 0.95;
	render_fractal(fract);
	return (0);
}

void	create_hooks(t_fract *fract)
{
		mlx_key_hook(fract->win, &handle_key, fract);
		mlx_mouse_hook(fract->win, &handle_mouse, fract);
		mlx_hook(fract->win, 17, 0, &close_win, fract);
}