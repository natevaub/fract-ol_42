/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:40:54 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 11:42:58 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

int	ft_color(t_params *params, int i)
{
	double	shading;
	int		max_iter;

	max_iter = params->iter;
	shading = 155 / max_iter * i * i;
	if (i < params->iter && params->colorset == 1)
		return (encode_rgb(shading / 2, 40 + shading, shading / 8));
	else if (i < params->iter && params->colorset == 2)
		return (encode_rgb(50 + shading, shading / 4, shading));
	else if (i < params->iter && params->colorset == 3)
		return (encode_rgb(shading / 8, shading / 2, 100 + shading));
	else
		return (encode_rgb(0, 0, 0));
}
