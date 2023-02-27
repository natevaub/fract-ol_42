/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:14:16 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 13:35:01 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

void	handle_new_julia(int keycode, t_data *data)
{
	if (keycode == 101)	/* Real part 'E' -- */
		data->params.julia_real -= 0.1;
	else if (keycode == 114) /* Real part 'R'  ++ */
		data->params.julia_real += 0.1;
	else if (keycode == 105) /* Imaginary part 'I' -- */
		data->params.julia_img -= 0.1;
	else if (keycode == 111) /* Imaginary part 'O' ++ */
		data->params.julia_img += 0.1;
}

int	key_hook(int keycode, t_data *data)
{
	ft_printf("Keycode = %d\n", keycode);
	handle_color_set(keycode, data);
	handle_panning(keycode, data);
	handle_clean_close(keycode, data);
	handle_fractal_type(keycode, data);
	handle_new_julia(keycode, data);
	reset_fractal_state(keycode, data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	calculate_zoom(keycode, x, y, data);
	zoom_fractal(keycode, x, y, data);
	return (0);
}

int	ft_handle_exit(void)
{
	exit(1);
	return (0);
}
