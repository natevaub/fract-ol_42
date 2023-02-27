/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:44:27 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 13:07:53 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

t_params	initialize_params(void)
{
	t_params	params;

	params.bottom = -2;
	params.top = 2;
	params.left = -2;
	params.right = 2;
	params.panOffset = 0.05;
	params.zoomInScale = 1.1;
	params.zoomOutScale = 1;
	params.iter = 100;
	params.julia_real = -0.8;
	params.julia_img = 0.156;
	return (params);
}

t_data	initialize_data(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_handle_exit();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "buffer");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		ft_handle_exit();
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	return (data);
}

t_data	initialize_data_from_args(int ac, char **av)
{
	t_data		data;
	t_params	params;

	data = initialize_data();
	params = initialize_params();
	data.params = params;
	if (ac != 3)
	{
		ft_printf("Unvalid numbers of argument please run:\n./fractol"
			" <name> (Mandelbrot, Julia, Burningship) <colorset> (1, 2, 3)");
		exit(1);
	}
	data.params.name = av[1];
	data.params.colorset = ft_atoi(av[2]);
	if (!(ft_strcmp(data.params.name, "Mandelbrot") == 0)
		&& !(ft_strcmp(data.params.name, "Julia") == 0)
		&& !(ft_strcmp(data.params.name, "Burningship") == 0))
	{
		ft_printf("Invalid name");
		ft_handle_exit();
	}
	return (data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data = initialize_data_from_args(ac, av);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, ft_handle_exit, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	free(data.mlx_ptr);
}
