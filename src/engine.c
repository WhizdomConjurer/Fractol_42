/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:31:13 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 15:31:38 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

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