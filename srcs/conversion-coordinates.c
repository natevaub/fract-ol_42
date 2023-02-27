/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion-coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:10:39 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/16 14:34:10 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

t_complex	plane_to_screen(t_complex c, t_params *params)
{
	t_complex	res;
	double		plane_w;
	double		plane_h;
	double		d_x;
	double		d_y;

	plane_w = params->right - params->left;
	plane_h = params->bottom - params->top;
	d_x = WIDTH / plane_w;
	d_y = HEIGHT / plane_h;
	res.real = (c.real - params->left) * d_x;
	res.img = ((c.img - params->top) * d_y) * -1 + HEIGHT;
	return (res);
}

t_complex	screen_to_plane(t_complex c, t_params *params)
{
	t_complex	res;
	double		plane_w;
	double		plane_h;
	double		d_x;
	double		d_y;

	c.img = (c.img - HEIGHT) * -1;
	plane_w = params->right - params->left;
	plane_h = params->bottom - params->top;
	d_x = WIDTH / plane_w;
	d_y = HEIGHT / plane_h;
	res.real = (c.real / d_x) + params->left;
	res.img = (c.img / d_y) + params->top;
	return (res);
}
