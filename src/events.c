/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:02:20 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 17:26:43 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void    view_port(int key, t_engine *engine)
{
    double		delta;
    
    delta = (engine->max_x - engine->min_x) / 20.0;
    if (key == MLX_KEY_UP)
		engine->offset_y -= delta;
	else if (key == MLX_KEY_DOWN)
		engine->offset_y += delta;
	else if (key == MLX_KEY_LEFT)
		engine->offset_x -= delta;
	else if (key == MLX_KEY_RIGHT)
		engine->offset_x += delta;
}

static void	ft_position_zoom(t_engine *engine, double zoom_factor)
{
	double	mouse_x;
	double	mouse_y;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(engine->mlx, &x, &y);
	mouse_x = engine->min_x + ((double)x / WIDTH) * (engine->max_x
			- engine->min_x);
	mouse_y = engine->min_y + ((double)y / HEIGHT) * (engine->max_y
			- engine->min_y);
	engine->min_x = mouse_x + (engine->min_x - mouse_x) * zoom_factor;
	engine->max_x = mouse_x + (engine->max_x - mouse_x) * zoom_factor;
	engine->min_y = mouse_y + (engine->min_y - mouse_y) * zoom_factor;
	engine->max_y = mouse_y + (engine->max_y - mouse_y) * zoom_factor;
}

void	ft_func_scroll(double xdelta, double ydelta, void *param)
{
	t_engine	*engine;
	double		zoom_factor;

	(void)xdelta;
	engine = (t_engine *)param;
	if (ydelta > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	ft_position_zoom(engine, zoom_factor);
	ft_draw_engine(engine);
}

void	ft_key_func(mlx_key_data_t mkd, void *param)
{
    t_engine    *engine;

    engine = (t_engine *)param;
    if(mkd.action != MLX_PRESS)
        return ;
    if (mkd.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(engine->mlx);
		exit(0);
	}
    else if (mkd.key >= MLX_KEY_RIGHT && mkd.key <= MLX_KEY_UP)
        view_port(mkd.key, engine);
    else if (mkd.key >= MLX_KEY_1 && mkd.key <= MLX_KEY_4)
        change_fractal(mkd.key, engine);
    else if (mkd.key == MLX_KEY_0)
        ft_reset_engine(engine);
    ft_draw_engine(engine);
}