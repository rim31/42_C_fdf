#include "fdf.h"
#include <stdio.h>

static void			ft_y(int a, int b, float c, t_env e)
{
	ft_putendl(" a, b, c ");
	ft_putnbr(a);
	ft_putstr(" ");
	ft_putnbr(b);
	ft_putstr(" ");
	ft_putnbr(c);
	e.b = (float)b;
	e.c = c * cosf(e.ydeg) - a * sinf(e.ydeg);
	e.a = c * sinf(e.ydeg) + a * cosf(e.ydeg);
	ft_putendl("rotation");
	ft_putnbr(e.a);
	ft_putstr(" ");
	ft_putnbr(e.b);
	ft_putstr(" ");
	ft_putnbr(e.c);
}

static void			ft_y2(int aa, int bb, float cc, t_env e)
{
	e.bb = (float)bb;
	e.cc = cc * cosf(e.ydeg) - aa * sinf(e.ydeg);
	e.aa = cc * sinf(e.ydeg) + aa * cosf(e.ydeg);
	ft_putnbr(e.aa);
	ft_putstr(" ");
	ft_putnbr(e.bb);
	ft_putstr(" ");
	ft_putnbr(e.cc);
}

static void	ft_linehoriz2(t_env a)
{
	a.xi = a.k * (a.a - a.x / 2 - a.l * a.c) + (2000 - a.x) / 2 + a.rightleft;
	a.yi = a.k * (a.b - a.l * a.c - a.y / 2) + (1000 - a.y) / 2 + a.updown;
	a.xf = a.k * (a.aa - a.x / 2 - a.l * a.cc) + (2000 - a.x) / 2 + a.rightleft;
	a.yf = a.k * (a.bb - a.l * a.cc - a.y / 2)	+ (1000 - a.y) / 2 + a.updown;
	ft_mlx_line(&a);
}

static void	ft_linevert2(t_env a)
{
	a.xi = a.k * (a.a - a.x / 2 - a.l * a.c) + (2000 - a.x) / 2 + a.rightleft;
	a.yi = a.k * (a.b - a.l * a.c - a.y / 2) + (1000 - a.y) / 2 + a.updown;
	a.xf = a.k * (a.aa - a.x / 2 - a.l * a.cc)	+ (2000 - a.x) / 2 + a.rightleft;
	a.yf = a.k * ((a.bb) - a.l * a.cc - a.y / 2) + (1000 - a.y) / 2 + a.updown;
	ft_mlx_line(&a);
}

t_env	ft_draw2(t_env *a)
{
	a->image = mlx_new_image(a->mlx, 2000, 1000);
	a->dr.data = mlx_get_data_addr(a->image, &a->dr.bpp,
		&a->dr.size_line, &a->dr.endian);
	a->j = 0;
	while (a->j < a->y)
	{
		a->i = 0;
		while (a->i < a->x)
		{
			if (a->i > 0)
			{
				ft_y(a->i, a->j, ft_atoi(a->tab[a->j][a->i]), *a);
				ft_y2((a->i - 1), a->j, ft_atoi(a->tab[a->j][a->i - 1]), *a);
				ft_linehoriz2(*a);
			}
			if (a->j > 0)
			{
				ft_y(a->i, a->j, ft_atoi(a->tab[a->j][a->i]), *a);
				ft_y2(a->i, a->j - 1, ft_atoi(a->tab[a->j][a->i - 1]), *a);
				ft_linevert2(*a);
			}
			a->i++;
		}
		a->j++;
	}
	mlx_put_image_to_window(a->mlx, a->win, a->image, 0, 0);
	return (*a);
}
