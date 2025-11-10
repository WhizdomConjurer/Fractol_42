/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:10:56 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 17:12:25 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static uint32_t	ft_color_prozess(t_engine *engine)
{
	if (engine->set == 1)
		return (ft_get_color_mandelbrot(engine));
	else if (engine->set == 2)
		return (ft_get_color_julia(engine));
	else if (engine->set == 3)
		return (ft_get_color_phoenix(engine));
	else
		return (ft_get_color_burningship(engine));
}

void	ft_draw_engine(t_engine *engine)
{
	int		x;
	int		y;
	double	x_mapped;
	double	y_mapped;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x_mapped = (engine->min_x + (x * (engine->max_x - engine->min_x))
					/ WIDTH) / engine->zoom + engine->offset_x;
			y_mapped = (engine->min_y + (y * (engine->max_y - engine->min_y))
					/ HEIGHT) / engine->zoom + engine->offset_y;
			ft_engine_calculate(x_mapped, y_mapped, engine);
			mlx_put_pixel(engine->img, x, y, ft_color_prozess(engine));
			++y;
		}
		++x;
	}
}