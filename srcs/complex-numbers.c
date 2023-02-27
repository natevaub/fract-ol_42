/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex-numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:56:07 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/16 13:58:38 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

t_complex	add_complex(t_complex c1, t_complex c2)
{
	t_complex	x;

	x.real = c1.real + c2.real;
	x.img = c1.img + c2.img;
	return (x);
}

t_complex	mult_complex(t_complex c1, t_complex c2)
{
	t_complex	x;

	x.real = c1.real * c2.real - c1.img * c2.img;
	x.img = c1.real * c2.img + c1.img * c2.real;
	return (x);
}

t_complex	square_complex(t_complex c)
{
	t_complex	res;

	res.real = c.real * c.real - c.img * c.img;
	res.img = 2 * c.real * c.img;
	return (res);
}

t_complex	abs_complex(t_complex c)
{
	t_complex	res;

	res.real = fabs(c.real);
	res.img = fabs(c.img);
	return (res);
}

float	distance(t_complex c)
{	
	return (sqrt(c.real * c.real + c.img * c.img));
}
