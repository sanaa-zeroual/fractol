/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeroual <szeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:10:03 by szeroual          #+#    #+#             */
/*   Updated: 2024/05/23 10:36:09 by szeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int	is_valid(char *av)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (av[i] && av[i] == ' ')
	{
		i++;
	}
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && (ft_isdigit(av[i]) || (av[i] == '.' && av[i + 1])
			|| av[i] == ' '))
	{
		if (av[i] == '.')
			f++;
		if (f == 2)
			return (0);
		i++;
	}
	return (ft_strlen(av) == i && i != 0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	setup_fractal(&vars, argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Mandelbrot and Julia");
	vars.zoom = 1.0;
	draw_fractal(&vars);
	mlx_mouse_hook(vars.win, mous_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
