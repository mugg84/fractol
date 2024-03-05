/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:18:28 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/15 15:18:25 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 800
# define WIDTH 800
# define ON_DESTROY 17
# define ITERATIONS 20

# define BLACK    0x000000
# define WHITE    0xFFFFFF
# define RED      0xFF0000
# define GREEN    0x00FF00
# define BLUE     0x0000FF
# define YELLOW   0xFFFF00
# define CYAN     0x00FFFF
# define MAGENTA  0xFF00FF
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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	char	*name;
	int		max_iter;
	int		is_ship;
	double	escape_val;
	double	julia_x;
	double	julia_y;
	double	zoom;
	double	move_x;
	double	move_y;
	t_img	img;
}	t_fract;

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

void		init(t_fract *fract);
void		malloc_err(void);
void		pixel_put(int x, int y, t_img *img, int colour);
void		render_fract(t_fract *fract);
void		get_hooks(t_fract *fract);
void		get_fract_type(t_complex *z, t_complex *c, t_fract *fract);
void		input_err(void	);
void		handle_pxl(int x, int y, t_fract *fract);
void		add_data(t_fract *fract);
double		atod(char *str);
double		scale(double num, double new_min, double new_max, double old_max);
int			handle_key(int keycode, t_fract *fract);
int			handle_mouse(int mouse_btn, int x, int y, t_fract *fract);
int			close_win(t_fract *fract);
t_complex	calc_complex(t_complex z, t_complex c, t_fract *fract);

#endif