/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:25:58 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/18 12:21:17 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MALLOC_ERROR	1
# define WIDTH			800
# define HEIGHT			800
//colours
# define BLACK    0x000000
# define WHITE    0xFFFFFF
# define RED      0xFF0000
# define GREEN    0x00FF00
# define BLUE     0x0000FF
# define YELLOW   0xFFFF00
# define CYAN     0x00FFFF
# define MAGENTA  0xFF00FF
// psychedelic
# define SUNSET_ORANGE 0xFD5E53
# define COSMIC_PURPLE 0x6B3FA0
# define ELECTRIC_BLUE 0x7DF9FF
# define LEMON_YELLOW 0xFFF44F
# define RASPBERRY_RED 0xFF005C
# define TURQUOISE_BLUE 0x00CED1
# define SPRING_GREEN 0x00FF7F
# define MAGENTA_BURST 0xFF00FF
# define HOT_PINK 0xFF69B4
# define ELECTRIC_PURPLE 0xBF00FF
# define LIME_GREEN 0x32CD32
# define AQUAMARINE 0x7FFFD4
# define CORAL 0xFF7F50

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>// TODO: delete

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct	s_fract {
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_val;
	int		iteration_def;
	double	zoom;
}	t_fract;

typedef struct s_complex_num
{
	double	real;
	double	i;
}	t_complex_num;

void	malloc_err(void);
double	scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
int	handle_key(int keycode, t_fract *fract);
void	create_hooks(t_fract *fract);
t_complex_num	calc_complex(t_complex_num *z, t_complex_num *c);
void	create_data(t_fract *fract);
void	render_fractal(t_fract *fract);
void	init(t_fract *fract);
void	put_pxl(int x, int y, t_img *img, int colour);
void	handle_pxl(int x, int y, t_fract *fract);
int	close_win(t_fract *fract);

#endif