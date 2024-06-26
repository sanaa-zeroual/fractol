/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeroual <szeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:44:19 by szeroual          #+#    #+#             */
/*   Updated: 2024/05/22 22:23:49 by szeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	julia(double cr, double ci, t_vars *vars)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	vars->max_iter = 60;
	x = cr;
	y = ci;
	i = 0;
	while (sqrt(x * x + y * y) <= 2.0 && i < vars->max_iter)
	{
		tmp = x * x - y * y + vars->com.real;
		y = 2 * x * y + vars->com.img;
		x = tmp;
		i++;
	}
	return (i);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_window(vars);
	return (0);
}

int	mous_hook(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key == 4)
		vars->zoom *= 1.15;
	if (key == 5)
		vars->zoom *= 0.85;
	mlx_destroy_image(vars->mlx, vars->img);
	draw_fractal(vars);
	return (0);
}

void	print_msg(void)
{
	char	*msg;

	msg = "invalid parameter choose julia or mandelbrot\n\
            ./fractol mandelbrot\n\
            ./fractol julia <real> <i>";
	write(1, msg, 117);
	exit(1);
}

void	setup_fractal(t_vars *vars, int argc, char **argv)
{
	if (argc < 2)
		print_msg();
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0 && is_valid(argv[2])
		&& is_valid(argv[3]))
	{
		vars->com.real = ft_atof(argv[2]);
		vars->com.img = ft_atof(argv[3]);
		vars->name = 0;
	}
	else if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		vars->name = 1;
	}
	else
		print_msg();
}
