/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeroual <szeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:44:30 by szeroual          #+#    #+#             */
/*   Updated: 2024/05/23 09:19:25 by szeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mandelbrot(double cr, double ci, t_vars *vars)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	x = 0;
	y = 0;
	i = 0;
	while (sqrt(x * x + y * y) <= 2.0 && i < vars->max_iter)
	{
		tmp = x * x - y * y + cr;
		y = 2 * x * y + ci;
		x = tmp;
		i++;
	}
	return (i);
}

double	ft_map(int point, double ref, double min, double max)
{
	return ((double)(point * (max - min)) / ref + min);
}

int	draw_pixel(int x, int y, t_vars *vars)
{
	int		iter;
	double	cr;
	double	ci;

	vars->max_iter = 60;
	cr = ft_map(x, WIDTH, -2.0, 2.0) * vars->zoom;
	ci = ft_map(y, HEIGHT, 2.0, -2.0) * vars->zoom;
	if (vars->name)
		iter = mandelbrot(cr, ci, vars);
	else
		iter = julia(cr, ci, vars);
	if (iter == vars->max_iter)
		return (NOIR);
	return (BLEU * iter / vars->max_iter);
}

void	draw_fractal(t_vars *vars)
{
	int		x;
	int		y;
	char	*p;

	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img_data = mlx_get_data_addr(vars->img, &vars->img_bpp,
			&vars->img_size_line, &vars->img_endian);
	p = NULL;
	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			p = vars->img_data + (x * vars->img_bpp / 8 + y
					* vars->img_size_line);
			*(unsigned int *)p = draw_pixel(x, y, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
