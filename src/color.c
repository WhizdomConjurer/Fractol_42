/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:03:55 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 17:07:56 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

// Mandelbrot: Blau-Violett
uint32_t	ft_get_color_mandelbrot(t_engine *engine)
{
	double	angle;
	int		r;
	int		g;
	int		b;
	float	gradient;

	if (engine->iter == engine->max_iter)
		return (0x000000FF);
	gradient = 0.15;
	angle = gradient * engine->iter + 0.2;
	r = (int)(100 + 80 * sin(angle));
	g = (int)(50 + 50 * sin(angle + 1.5));
	b = (int)(200 + 55 * sin(angle + 3.0));
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

// Julia: Türkis-Grün
uint32_t	ft_get_color_julia(t_engine *engine)
{
	double	angle;
	int		r;
	int		g;
	int		b;
	float	gradient;

	if (engine->iter == engine->max_iter)
		return (0x000000FF);
	gradient = 0.18;
	angle = gradient * engine->iter + 0.3;
	r = (int)(40 + 40 * sin(angle + 2.5));
	g = (int)(180 + 75 * sin(angle));
	b = (int)(150 + 60 * sin(angle + 1.0));
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

// Burning Ship: Orange-Rot
uint32_t	ft_get_color_burningship(t_engine *engine)
{
	double	angle;
	int		r;
	int		g;
	int		b;
	float	gradient;

	if (engine->iter == engine->max_iter)
		return (0x000000FF);
	gradient = 0.25;
	angle = gradient * engine->iter + 0.1;
	r = (int)(200 + 55 * sin(angle));
	g = (int)(100 + 80 * sin(angle + 3.0));
	b = (int)(40 + 40 * sin(angle + 5.0));
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

// Phönix: Pink-Blau
uint32_t	ft_get_color_phoenix(t_engine *engine)
{
	double	angle;
	int		r;
	int		g;
	int		b;
	float	gradient;

	if (engine->iter == engine->max_iter)
		return (0x000000FF);
	gradient = 0.22;
	angle = gradient * engine->iter + 0.25;
	r = (int)(180 + 60 * sin(angle + 1.0));
	g = (int)(70 + 60 * sin(angle + 3.2));
	b = (int)(220 + 30 * sin(angle));
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}