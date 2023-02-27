/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:45:09 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 13:23:29 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_UP_H
#define SET_UP_H

/* Utils Library */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <complex.h>
#include <stdint.h>
#include "../libmlx/mlx.h"
#include "libs/ftprintf/ft_printf.h"

/* Dimensions Canvas */
#define WIDTH 600
#define HEIGHT 600

/* Structs */

typedef struct s_params
{
	double	left;
	double 	right;
	double	top;
	double	bottom;
	double	panOffset;
	double	zoomInScale;
	double	zoomOutScale;
	double	julia_real;
	double	julia_img;
	char	*name;				// Fractol type (mandelbrot, julia, burningship)
	int		colorset;
	int		iter;
	int		i;
	int		j;
}	t_params;

typedef struct	s_zoom
{
	double	new_width;
	double	new_height;
	double	x_ratio;
	double	y_ratio;
	double	new_left;
	double	new_bottom;
}	t_zoom;

typedef struct s_complex {
	double	real;
	double	img;
}	t_complex;

typedef struct s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_params params;
	t_zoom	zoom;
}	t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define K_ESC 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100
# define K_P 112
# define K_MINUS 61
# define K_PLUS 10
# define K_R 114
# define K_U 117
# define K_J 106
# define K_I 105
# define K_K 107
# define K_O 111
# define K_L 108
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define ESC 53

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define ESC 53

/* Functions */
/* struct initialisation */
/* libft */
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *nptr);
int			intlen(int n);
void		handle_negative(long *nbr, char **result);
char		*ft_itoa(int n);
/* complex-numbers */
t_complex	add_complex(t_complex c1, t_complex c2);
t_complex	mult_complex(t_complex c1, t_complex c2);
t_complex	square_complex(t_complex c);
t_complex	abs_complex(t_complex c);
float		distance(t_complex c);
/* fractals-algo */
int			quad_mandelbrot(t_complex c1, int iter);
int			quad_julia(t_complex c1, int iter, t_params *params);
int			quad_burningship(t_complex c1, int iter);
/* zoom */
void		calculate_zoom(int keycode, int x, int y, t_data *data);
int			zoom_fractal(int keycode, int x, int y, t_data *data);
/* conversion-coordinates */
t_complex	plane_to_screen(t_complex c, t_params *params);
t_complex	screen_to_plane(t_complex c, t_params *params);
/* events */
void		handle_color_set(int keycode, t_data *data);
void		handle_panning(int keycode, t_data *data);
void		handle_clean_close(int keycode, t_data *data);
void		handle_fractal_type(int keycode, t_data *data);
void		reset_fractal_state(int keycode, t_data *data);
void		handle_new_julia(int keycode, t_data *data);
int			key_hook(int keycode, t_data *data);
int			mouse_hook(int keycode, int x, int y, t_data *data);
int			ft_handle_exit();
/* rendering */
void		render_mandelbrot(t_img *img, t_params *params);
void		render_burningship(t_img *img, t_params *params);
void		render_julia(t_img *img, t_params *params);
int			render(t_data *data);
/* utils */
int			ft_color(t_params *params, int i);
int			encode_rgb(uint8_t r, uint8_t g, uint8_t b);
void		img_pix_put(t_img *img, int x, int y, int color);
void		fract_parameters(t_data *data);

#define MLX_ERROR 1


#endif


