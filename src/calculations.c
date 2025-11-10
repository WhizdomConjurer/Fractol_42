/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:09 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 17:58:02 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	ft_mandelbrot_calculate(double x, double y, t_engine *engine)
{
	int		i;
	double	zx_temp;

	i = 0;
	engine->zx = 0;
	engine->zy = 0;
	while (i < engine->max_iter)
	{
		zx_temp = engine->zx * engine->zx - engine->zy * engine->zy + x;
		engine->zy = 2.0 * engine->zx * engine->zy + y;
		engine->zx = zx_temp;
		if (engine->zx * engine->zx + engine->zy * engine->zy > 4)
			return (i);
		++i;
	}
	return (i);
}

int	ft_julia_calculate(double x, double y, t_engine *engine)
{
	int		i;
	double	zx_temp;

	i = 0;
	engine->zx = -x;
	engine->zy = y;
	while (i < engine->max_iter)
	{
		zx_temp = engine->zx * engine->zx
			- engine->zy * engine->zy + engine->julia_r;
		engine->zy = 2.0 * engine->zx * engine->zy + engine->julia_i;
		engine->zx = zx_temp;
		if (engine->zx * engine->zx + engine->zy * engine->zy > 4)
			return (i);
		++i;
	}
	return (i);
}

int	ft_phoenix_calculate(double x, double y, t_engine *engine)
{
	int		i;
	double	prev_zx;
	double	prev_zy;
	double	new_zx;
	double	new_zy;

	engine->zx = 0;
	engine->zy = 0;
	prev_zx = 0;
	prev_zy = 0;
	i = 0;
	while (i < engine->max_iter && (engine->zx * engine->zx
			+ engine->zy * engine->zy) <= 4.0)
	{
		new_zx = engine->zx * engine->zx - engine->zy * engine->zy
			+ x + engine->phoenix_p * prev_zx;
		new_zy = 2.0 * engine->zx * engine->zy
			+ y + engine->phoenix_p * prev_zy;
		prev_zx = engine->zx;
		prev_zy = engine->zy;
		engine->zx = new_zx;
		engine->zy = new_zy;
		++i;
	}
	return (i);
}

int	ft_burning_ship_calculate(double x, double y, t_engine *engine)
{
	int		i;
	double	x0;
	double	y0;

	i = 0;
	engine->zx = x;
	engine->zy = y;
	x = 0;
	y = 0;
	while (i < engine->max_iter)
	{
		x0 = x * x - y * y + engine->zx;
		y0 = 2.0 * fabs(x * y) + engine->zy;
		x = fabs(x0);
		y = fabs(y0);
		if (x * x + y * y > 4)
		{
			return (i);
		}
		++i;
	}
	return (i);
}

void	ft_engine_calculate(double mapped_x, double mapped_y,
	t_engine *engine)
{
	if (engine->set == 1)
		engine->iter = ft_mandelbrot_calculate(mapped_x, mapped_y, engine);
	else if (engine->set == 2)
		engine->iter = ft_julia_calculate(mapped_x, mapped_y, engine);
	else if (engine->set == 3)
		engine->iter = ft_phoenix_calculate(mapped_x, mapped_y, engine);
	else if (engine->set == 4)
		engine->iter = ft_burning_ship_calculate(mapped_x, mapped_y, engine);
}