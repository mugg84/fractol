/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:55:01 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/15 15:07:11 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	handle_key(int keycode, t_fract *fract)
{
	if (keycode == XK_Escape)
		close_win(fract);
	if (keycode == XK_Up)
		fract->move_y += (0.5 * fract->zoom);
	else if (keycode == XK_Down)
		fract->move_y -= (0.5 * fract->zoom);
	else if (keycode == XK_Right)
		fract->move_x += (0.5 * fract->zoom);
	else if (keycode == XK_Left)
		fract->move_x -= (0.5 * fract->zoom);
	else if (keycode == XK_w)
		fract->max_iter += 5;
	else if (keycode == XK_s && fract->max_iter > 10)
		fract->max_iter -= 5;
	render_fract(fract);
	return (0);
}

int	handle_mouse(int mouse_btn, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (mouse_btn == 4)
		fract->zoom *= 1.05;
	else if (mouse_btn == 5)
		fract->zoom *= 0.95;
	render_fract(fract);
	return (0);
}

void	get_hooks(t_fract *fract)
{
	mlx_hook(fract->win, ON_DESTROY, 0, &close_win, fract);
	mlx_key_hook(fract->win, &handle_key, fract);
	mlx_mouse_hook(fract->win, &handle_mouse, fract);
}

int	close_win(t_fract *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
