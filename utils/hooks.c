/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:53 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/17 14:05:39 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	create_hooks(t_fract *fract)
{
		mlx_key_hook(fract->win, &close_win, &fract);
}