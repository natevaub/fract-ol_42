/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info-parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:15:03 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/21 23:52:13 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

void	fract_parameters(t_data *data)
{
	char	*fract_name;
	char	*colorset;

	fract_name = data->params.name;
	colorset = ft_itoa(data->params.colorset);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xFFFFFF,
		"Fractol Type ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 120, 20, 0xFFFFFF, fract_name);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 300, 20, 0xFFFFFF, "(4-5-6)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0xFFFFFF, "Colorset ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 120, 40, 0xFFFFFF, colorset);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 300, 40, 0xFFFFFF, "(1-2-3)");
	free(colorset);
}
