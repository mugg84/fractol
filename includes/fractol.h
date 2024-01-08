/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:58 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/08 16:12:17 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define MALLOC_ERROR	1
#define WIDTH			400
#define	HEIGHT			400

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>//to delete


typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;


#endif