/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:21:26 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 13:13:40 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

void	calculate_zoom(int keycode, int x, int y, t_data *data)
{
	t_complex	screen_pos;
	t_complex	plane_pos;
	double		current_width;
	double		current_height;
	// if(keycode == 5 || keycode == 4)
	// 	y = WIDTH - y;
	screen_pos.real = x;
	screen_pos.img = y;
	plane_pos = screen_to_plane(screen_pos, &data->params);
	current_width = fabs(data->params.right - data->params.left);
	current_height = fabs(data->params.top - data->params.bottom);
	data->zoom.x_ratio = (plane_pos.real - data->params.left) / current_width;
	data->zoom.y_ratio = (plane_pos.img - data->params.bottom) / current_height;
	if (keycode == 4 || keycode == LEFT_CLICK)
	{
		data->zoom.new_width = current_width / 1.1;
		data->zoom.new_height = current_height / 1.1;
	}
	else if (keycode == 5 || keycode == RIGHT_CLICK)
	{
		data->zoom.new_width = current_width * 1.1;
		data->zoom.new_height = current_height * 1.1;
	}
	data->zoom.new_left = plane_pos.real - data->zoom.x_ratio
		* data->zoom.new_width;
	data->zoom.new_bottom = plane_pos.img - data->zoom.y_ratio
		* data->zoom.new_height;
}

int	zoom_fractal(int keycode, int x, int y, t_data *data)
{
	t_zoom	zoom;

	calculate_zoom(keycode, x, y, data);
	data->params.left = data->zoom.new_left;
	data->params.right = data->zoom.new_left + data->zoom.new_width;
	data->params.bottom = data->zoom.new_bottom;
	data->params.top = data->zoom.new_bottom + data->zoom.new_height;
	return (0);
}
