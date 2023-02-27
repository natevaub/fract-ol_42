/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:26:01 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 12:45:05 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

void	reset_fractal_state(int keycode, t_data *data)
{
	if (keycode == 26 || keycode == 55)
	{
		data->params.left = -2.0;
		data->params.right = 2.0;
		data->params.top = 2.0;
		data->params.bottom = -2.0;
	}
}

void	handle_fractal_type(int keycode, t_data *data)
{
	if (keycode == 21 || keycode == 52)
		data->params.name = "Mandelbrot";
	else if (keycode == 23 || keycode == 53)
		data->params.name = "Julia";
	else if (keycode == 22 || keycode == 54)
		data->params.name = "Burningship";
}

void	handle_color_set(int keycode, t_data *data)
{
	if (keycode == 18 || keycode == 49)
		data->params.colorset = 1;
	else if (keycode == 19 || keycode == 50)
		data->params.colorset = 2;
	else if (keycode == 20 || keycode == 51)
		data->params.colorset = 3;
}

void	handle_panning(int keycode, t_data *data)
{
	if (keycode == K_UP || keycode == UP)
	{
		data->params.top -= data->params.panOffset;
		data->params.bottom -= data->params.panOffset;
	}
	else if (keycode == K_DOWN || keycode == DOWN)
	{
		data->params.top += data->params.panOffset;
		data->params.bottom += data->params.panOffset;
	}
	else if (keycode == K_RIGHT || keycode == RIGHT)
	{
		data->params.left += data->params.panOffset;
		data->params.right += data->params.panOffset;
	}
	else if (keycode == K_LEFT || keycode == LEFT)
	{
		data->params.left -= data->params.panOffset;
		data->params.right -= data->params.panOffset;
	}
}

void	handle_clean_close(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 53)
		ft_handle_exit();
}
