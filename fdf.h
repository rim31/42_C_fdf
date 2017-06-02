/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:03:11 by oseng             #+#    #+#             */
/*   Updated: 2016/02/12 20:11:50 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 8

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef	struct	s_draw
{
	int			bpp;
	int			size_line;
	int			color;
	char		*data;
	int			endian;
}				t_draw;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*image;
	char		**str;
	char		***tab;
	int			**grid;
	int			x;
	int			y;
	int			i;
	int			j;
	int			d;
	double		zdeg;
	double		ydeg;
	double		xdeg;
	float		k;
	float		l;
	float		m;
	float		a;
	float		b;
	float		c;
	float		aa;
	float		bb;
	float		cc;
	float		xxi;
	float		yyi;
	float		xxf;
	float		yyf;
	float		updown;
	float		rightleft;
	float		xi;
	float		xf;
	float		yi;
	float		yf;
	int			ii;
	int			jj;
	int			kk;
	int			ll;
	t_draw		dr;
}				t_env;

int				ft_strnb(char const *s, char c);
int				my_key_funct(int keycode, t_env *a);
int				get_next_line(int const fd, char **line);
void			mlx_pixel_put_to_image(int x, int y, t_env *e);
void			ft_mlx_line(t_env *e);
void			ft_zrot(float *i, float *j, t_env e);
void			ft_zrota(float *k, float *l, t_env e);
void			ft_linehoriz(t_env a);
void			ft_linevert(t_env a);
t_env			ft_draw(t_env *a);
t_env			ft_mapping(t_env a);
t_env			ft_xyz(t_env e);
t_env			ft_parse(char **str);
t_env			ft_inival(void);

#endif
