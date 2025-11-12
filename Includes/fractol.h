/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:54:21 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 17:29:14 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1280
# define HEIGHT 960
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define PHOENIX 4
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"
# define PHOENIX_STR "phoenix"

# define WIDTH 1280
# define HEIGHT 960

typedef struct s_color_map
{
	int	key;
	int	delta;
}	t_color_map;

typedef struct s_engine
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**av;
	int			ac;
	int			set;
	int			max_iter;
	int			iter;
	float		zoom;
	double		zx;
	double		zy;
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;
	double		julia_r;
	double		julia_i;
	double		phoenix_p;
	double		offset_x;
	double		offset_y;
	uint32_t	color_shift;
}				t_engine;

void		ft_func_scroll(double xdelta, double ydelta, void *param);
void		change_fractal(int key, t_engine *engine);
void		ft_reset_engine(t_engine *engine);
void		ft_key_func(mlx_key_data_t mkd, void *param);
void		ft_draw_engine(t_engine *engine);
float		ft_atof(const char *str);
void		ft_init(t_engine *engine, int ac, char **av);
void		ft_error(void);
void		ft_engine_calculate(double mapped_x, double mapped_y,
				t_engine *engine);
uint32_t	ft_get_color_mandelbrot(t_engine *engine);
uint32_t	ft_get_color_julia(t_engine *engine);
uint32_t	ft_get_color_burningship(t_engine *engine);
uint32_t	ft_get_color_phoenix(t_engine *engine);
void		change_color(int key, t_engine *engine);

# ifdef __linux__

enum e_keys
{
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_R = 114,
	KEY_T = 116,
	KEY_Y = 121,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_L = 108,
	MOUSE_LEFT_CLK = 1,
	MOUSE_SCRL_CLK = 2,
	MOUSE_RIGHT_CLK = 3,
	MOUSE_SCRL_UP = 4,
	MOUSE_SCRL_DOWN = 5,
};

# else

enum e_keys
{
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_SIX = 22,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_R = 15,
	KEY_T = 17,
	KEY_Y = 16,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_L = 37,
	MOUSE_LEFT_CLK = 1,
	MOUSE_RIGHT_CLK = 2,
	MOUSE_SCRL_CLK = 3,
	MOUSE_SCRL_DOWN = 4,
	MOUSE_SCRL_UP = 5,
};
# endif
#endif