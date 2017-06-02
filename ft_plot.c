#include "fdf.h"

void	ft_plot(int **grid, int x, int y)
{
	t_env e;

	e.j = 0;
	e.x = 0;
	e.y = 0;
	e.z = 0;
	while (e.j < y - 1)
	{
		e.i = 0;
		while (e.i < x - 1)
		{
			
			e.i;
		}
	}

}

ft_rotate(int **grid, int x, int y)
{
	t_env e;

	//point initial : xi, yi  rotation   ->  point final: xf, yf;  angle en radian exemple : 0,05
	// xf = x*cos(angle) - y*sin(angle);
	// yf = y*cos(angle) + x*sin(angle);

	//rotation par rapport a l'axe X
	//point initial : xi, yi zi  rotation   ->  point final: xf, yf zf;  angle en radian exemple : 0,05
	// yf = y*cos(angle) - z*sin(angle);
	// zf = z*cos(angle) + y*sin(angle);

	//rotation par rapport a l'axe y
	//point initial : xi, yi, zi  rotation   ->  point final: xf, yf, zf;  angle en radian exemple : 0,05
	// xf = x*cos(angle) - z*sin(angle);
	// zf = z*cos(angle) + x*sin(angle);

	while (e.j++ < y-1)
	{

		e.i = 0;
		while (st[e.i])
		{

			e.grid[e.j][e.i] = ;
			ft_putnbr(e.grid[e.j][e.i]);
			ft_putstr("  ");
			e.i++;
		}
		ft_putchar('\n');
	}
}
