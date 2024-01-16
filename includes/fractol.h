/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:58 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/16 14:03:09 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define MALLOC_ERROR	1
#define WIDTH			400
#define	HEIGHT			400

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>// TODO: delete

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_data;

typedef struct	s_fract {
	void	*mlx;
	void	*win;
	t_data	img;
}	t_fract;


// typedef struct s_mlx_data
// {
// 	void	*mlx;
// 	void	*win;
// 	t_data	img;
// 	int		colour;

// }	t_mlx_data;
#endif