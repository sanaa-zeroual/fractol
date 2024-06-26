/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeroual <szeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:44:25 by szeroual          #+#    #+#             */
/*   Updated: 2024/05/22 21:43:40 by szeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 80
# define ESC 0xff1b
# define NOIR 0x000000
# define BLEU 0x00FFFF

typedef struct mlx
{
	double		real;
	double		img;
}				t_Complex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			img_bpp;
	int			maxiter;
	int			img_size_line;
	int			img_endian;
	double		zoom;
	int			max_iter;
	t_Complex	com;
	int			name;
}				t_vars;

int				ft_strcmp(char *s1, char *s2);
double			ft_atof(char *str);
double			cal(int i, double nb, char *str);
double			ft_map(int point, double ref, double min, double max);
int				draw_pixel(int x, int y, t_vars *vars);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
int				is_valid(char *av);
void			setup_fractal(t_vars *vars, int argc, char **argv);
void			print_msg(void);
int				key_hook(int keycode, t_vars *vars);
int				mous_hook(int key, int x, int y, t_vars *vars);
int				julia(double cr, double ci, t_vars *vars);
int				close_window(t_vars *vars);
void			draw_fractal(t_vars *vars);

#endif