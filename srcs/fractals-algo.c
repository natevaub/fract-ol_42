/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals-algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:26:41 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/23 11:17:09 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

int	quad_mandelbrot(t_complex c1, int iter)
{
	int			i;
	t_complex	z;
	t_complex	res;

	z.real = 0;
	z.img = 0;
	i = 0;
	while (i <= iter)
	{
		z = add_complex(mult_complex(z, z), c1);
		if (distance(z) > 4.0)
			return (i);
		i++;
	}
	return (0);
}

int	quad_burningship(t_complex c1, int iter)
{
	int			i;
	t_complex	z;

	z.real = 0;
	z.img = 0;
	i = 0;
	while (i <= iter)
	{
		z = add_complex(square_complex(abs_complex(z)), c1);
		if (distance(z) > 4.0)
			return (i);
		i++;
	}
	return (0);
}

int	quad_julia(t_complex c1, int iter, t_params *params)
{
	int			i;
	t_complex	z;
	t_complex	res;

	z.real = params->julia_real;
	z.img = params->julia_img;
	i = 0;
	while (i <= iter)
	{
		c1 = add_complex(mult_complex(c1, c1), z);
		if (distance(c1) > 4.0)
			return (i);
		i++;
	}
	return (0);
}
