/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:30:10 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 12:37:13 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

void	render_mandelbrot(t_img *img, t_params *params)
{
	t_complex	screen;
	t_complex	plane;
	int			it;
	int			color;

	params->i = 0;
	while (params->i < WIDTH)
	{
		params->j = HEIGHT / 8;
		while (params->j < HEIGHT)
		{
			screen.real = params->i;
			screen.img = params->j;
			plane = screen_to_plane(screen, params);
			it = quad_mandelbrot(plane, params->iter);
			color = ft_color(params, it);
			img_pix_put(img, screen.real, screen.img, color);
			params->j++;
		}
		params->i++;
	}
}

void	render_burningship(t_img *img, t_params *params)
{
	t_complex	screen;
	t_complex	plane;
	int			it;
	int			color;

	params->i = 0;
	while (params->i < WIDTH)
	{
		params->j = HEIGHT / 8;
		while (params->j < HEIGHT)
		{
			screen.real = params->i;
			screen.img = params->j;
			plane = screen_to_plane(screen, params);
			it = quad_burningship(plane, params->iter);
			color = ft_color(params, it);
			img_pix_put(img, screen.real, screen.img, color);
			params->j++;
		}
		params->i++;
	}
}

void	render_julia(t_img *img, t_params *params)
{
	t_complex	screen;
	t_complex	plane;
	int			it;
	int			color;

	params->i = 0;
	while (params->i < WIDTH)
	{
		params->j = HEIGHT / 8;
		while (params->j < HEIGHT)
		{
			screen.real = params->i;
			screen.img = params->j;
			plane = screen_to_plane(screen, params);
			it = quad_julia(plane, params->iter, params);
			color = ft_color(params, it);
			img_pix_put(img, screen.real, screen.img, color);
			params->j++;
		}
		params->i++;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (ft_strcmp(data->params.name, "Mandelbrot") == 0)
		render_mandelbrot(&data->img, &data->params);
	else if (ft_strcmp(data->params.name, "Julia") == 0)
		render_julia(&data->img, &data->params);
	else if (ft_strcmp(data->params.name, "Burningship") == 0)
		render_burningship(&data->img, &data->params);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	fract_parameters(data);
	return (0);
}
