/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:31:13 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 17:14:58 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_set_fractal(t_engine *engine)
{
	size_t	len;

	if (!engine)
		return ;
	len = ft_strlen(engine->av[1]);
	if (ft_strncmp(engine->av[1], MANDELBROT_STR, len) == 0)
		engine->set = MANDELBROT;
	else if (ft_strncmp(engine->av[1], JULIA_STR, len) == 0)
		engine->set = JULIA;
	else if (ft_strncmp(engine->av[1], BURNING_SHIP_STR, len) == 0)
		engine->set = BURNING_SHIP;
	else if (ft_strncmp(engine->av[1], PHOENIX_STR, len) == 0)
		engine->set = PHOENIX;
}

void	ft_reset_engine(t_engine *engine)
{
	engine->max_iter = 100;
	engine->zoom = 1.0;
	engine->zx = 0;
	engine->zy = 0;
	engine->offset_x = 0;
	engine->offset_y = 0;
	engine->min_x = -2.0;
	engine->max_x = 1.0;
	engine->min_y = -1.5;
	engine->max_y = 1.5;
	engine->color_shift = 0;
	if (engine->ac == 2)
	{
		engine->julia_r = 0.355;
		engine->julia_i = 0.355;
		engine->phoenix_p = -0.5;
	}
	else if (engine->ac == 4)
	{
		engine->julia_r = ft_atof(engine->av[2]);
		engine->julia_i = ft_atof(engine->av[3]);
		engine->phoenix_p = -0.5;
	}
	ft_set_fractal(engine);
}

void	ft_init(t_engine *engine, int ac, char **av)
{
	engine->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	if (!engine->mlx)
		exit(1);
	engine->img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	if (!engine->img)
		return (mlx_terminate(engine->mlx), exit(1));
	engine->ac = ac;
	engine->av = av;
	ft_reset_engine(engine);
}

void	change_fractal(int key, t_engine *engine)
{
	ft_reset_engine(engine);
	if (key == MLX_KEY_1)
		engine->set = MANDELBROT;
	else if (key == MLX_KEY_2)
		engine->set = JULIA;
	else if (key == MLX_KEY_3)
		engine->set = BURNING_SHIP;
	else if (key == MLX_KEY_4)
		engine->set = PHOENIX;
}
