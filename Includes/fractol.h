/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:54:21 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 15:15:12 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

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

# define WIDTH 1280
# define HEIGHT 960

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


#endif