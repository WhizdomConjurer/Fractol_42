/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:11:22 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 18:19:23 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

float	ft_atof(const char *str)
{
	float	res;
	float	sign;
	int		i;
	float	f;

	res = 0.0f;
	sign = 1.0f;
	i = 0;
	f = 1.0f;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10.0f + (str[i++] - '0');
	if (str[i] == '.')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0f + (str[i++] - '0');
		f *= 10.0f;
	}
	return (sign * res / f);
}

void	ft_error(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" +------------------ Let me help you! ---------------------+\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | Use: ./fractol [mandelbrot / julia [] [] / burning_ship |\n", 1);
	ft_putstr_fd(" |                   phoenix ]                             |\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | e.g: ./fractol mandelbrot                               |\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" |----------------------- KEYBOARD ------------------------|\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | Press ESC to close the window                           |\n", 1);
	ft_putstr_fd(" | Press one of [1-4] to move to another fractal           |\n", 1);
	ft_putstr_fd(" | Press one of [Q-Y] keys to change the color of fractal  |\n", 1);
	ft_putstr_fd(" | Press one of [A-H] keys to change the color of fractal  |\n", 1);
	ft_putstr_fd(" | Use mouse scroll to zoom in and out of the fractal      |\n", 1);
	ft_putstr_fd(" | Press the arrow keys to change the viewpoint            |\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | Press Zero to reset the fractal                         |\n", 1);
	ft_putstr_fd(" +---------------------------------------------------------+\n", 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_SUCCESS);
}

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}