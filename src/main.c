/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:53:58 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 17:22:34 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc < 2)
		ft_error();
	ft_init(&engine, argc, argv);
	mlx_key_hook(engine.mlx, ft_key_func, &engine);
	mlx_scroll_hook(engine.mlx, ft_func_scroll, &engine);
	mlx_image_to_window(engine.mlx, engine.img, 0, 0);
	ft_draw_engine(&engine);
	mlx_loop(engine.mlx);
	mlx_terminate(engine.mlx);
	return (0);
}
