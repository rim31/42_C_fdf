/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:58 by oseng             #+#    #+#             */
/*   Updated: 2016/02/09 15:19:41 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_funct(int keycode)
{
	printf("key event Clavier %d\n", keycode);
	if (keycode == 53) //si on appuie sr la touche echap
		exit (0);
	return (0);
}

static t_env ft_initval(void)
{
	t_env e;
	e.mlx = NULL;
	e.win = NULL;
	e.grid = 0;
	e.tab  = NULL;
	e.x = 0;//ft_mlx_line (x, y ,x, y, *win), longueur max
	e.y = 0;//ft_parse et ft_xyz, largeur max
	e.z = 0;
	e.i = 0;//ft_parse :longueur du double tableau **int
	e.j = 0;//ft_parse :largeur du double tableau **int
	e.k = 30;//coef sur la distance entre les points
	e.l = 0.1;//coef sur la hauteur des points
//	e.m = 0;
	e.a = 0;//ft_line
	e.b = 0;
//	e.c = 0;
	e.d = 0;
	e.Xi = 0;//coordonnees final a tracer
	e.Yi = 0;//coordonnees final a tracer
	e.Xf = 0;//coordonnees final a tracer
	e.Yf = 0;//coordonnees final a tracer
//	e.Z = 0;
	e.updown = 0;
	e.rightleft = 0;
	e.zoom = 0;
	e.angleup = 0;
	e.zdeg = 0.10;
	return (e);
}

void ft_mlx_line(int xi, int yi, int xf, int yf, t_env *e)
{
	t_env c;

	c = ft_initval();
	c.d = (xi == xf) ? 100 * abs(yf - yi) : 100 * abs(xf - xi); //nombre de pixel a parcourir pour tracer les lignes
	c.a = (xi == xf) ? 1 : (((float)yf - (float)yi) / ((float)xf - (float)xi));
	c.Xi = xi;
	c.b = yi - c.a * xi;
	c.i = -1;
	while (c.i++ <= c.d) //i +0,01 pour pouvoir avoir une bonne definition
	{
		if (xi != xf)
		{
			c.Yi = c.a * c.Xi + c.b;
			c.Xi = (xi < xf) ? c.Xi + 0.01 : c.Xi - 0.01;
		}
		else
			c.Yi = (yi < yf) ?  0.01 * c.i + yi : yi - 0.01 * c.i;
		mlx_pixel_put(e->mlx, e->win, c.Xi, c.Yi, 0xFFFFFF);
	}
}

static int      ft_strnb(char const *s, char c)
{
	size_t  a;
	size_t  i;
	size_t  nb;
	int             begin;
	int             end;

	nb =    0;
	a =             0;
	i =             0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		begin = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > begin)
			nb++;
	}
	return (nb);
}





static void 	ft_zrot(float *i, float *j, float *k, float *l, t_env e)
{
	float x;
	float y;
	float v;
	float w;
	//double zdeg;

	x = *i;
	y = *j;
	v = *k;
	w = *l;
	e.zdeg = 0.10;
	*i = x * cosf(e.zdeg) - y * sinf(e.zdeg) /*+ x * cos(ydeg) - z * sin(ydeg)*/;
	*j = y * cosf(e.zdeg) - x * sinf(e.zdeg)/* + y * cos(xdeg) - z * sin(xdeg)*/;
	*k = v * cosf(e.zdeg) - w * sinf(e.zdeg) /*+ x * cos(ydeg) - z * sin(ydeg)*/;
	*l = w * cosf(e.zdeg) - v * sinf(e.zdeg);
}

static void linehoriz(t_env a, int i, int j, int k, int l)
{
	a.Xi = a.k *(i - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
	a.Yi = a.k *(j - a.l * ft_atoi(a.tab[j][i]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
	a.Xf = a.k *((k) - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
	a.Yf = a.k *(l - a.l * ft_atoi(a.tab[l][k]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
//printf("normal Xi:%f, Yi:%f, Xf:%f, Yf:%f\n", a.Xi, a.Yi, a.Xf, a.Yf);
	ft_zrot(&a.Xi, &a.Yi, &a.Xf, &a.Yf, a);
//printf("rotaion Xi:%f, Yi:%f, Xf:%f, Yf:%f\n", a.Xi, a.Yi, a.Xf, a.Yf);
	ft_mlx_line(a.Xi, a.Yi, a.Xf, a.Yf, &a);
}

static void linevert(t_env a, int i, int j, int k, int l)
{
	a.Xi = a.k *(i - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
	a.Yi = a.k *(j - a.l * ft_atoi(a.tab[j][i]) - a.y/2) + (1000 - a.y) / 2 + a.updown;

	a.Xf = a.k *((k) - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
	a.Yf = a.k *((l) - a.l * ft_atoi(a.tab[l][k]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
ft_zrot(&a.Xi, &a.Yi, &a.Xf, &a.Yf, a);
	ft_mlx_line(a.Xi, a.Yi, a.Xf, a.Yf, &a);
}

/*on trace les
*/
static t_env	ft_mapping(t_env a)
{
	//ft_putnbr(a.grid[3][3]);
	//t_env a;
	a.j = 0;
	a.rightleft = 0;
	a.updown = 0;
	a.l = 0.1; //coef pour l'axe z
	a.k = 30; //coef entre les lignes

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 2000, 1000, "mlx 42");
	//while (a.j < 100 * (y - 2)) //je veux tracer des trait noirs qund il y a pas de traits blancs
	while (a.j < a.y)
	{
		a.i = 0;
		while (a.i < a.x)
		{
			if (a.i > 0)
			{
				linehoriz(a, a.i, a.j, a.i - 1, a.j);
				// a.Xi = a.k *(a.i - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
				// a.Yi = a.k *(a.j - a.l * ft_atoi(a.tab[a.j][a.i]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
				// a.Xf = a.k *((a.i - 1) - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
				// a.Yf = a.k *(a.j - a.l * ft_atoi(a.tab[a.j][a.i - 1]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
				//
				// //printf("(%.0f,%.0f,%s) - (%.0f,%.0f,%s)\n",a.Xi, a.Yi, a.tab[a.j][a.i], a.Xf, a.Yf, a.tab[a.j][a.i+1]);
				// ft_mlx_line(a.Xi, a.Yi, a.Xf, a.Yf, &a);
			}
			if (a.j > 0)
			{
				linevert(a, a.i, a.j, a.i, a.j - 1);
				// a.Xi = a.k *(a.i - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
				// a.Yi = a.k *(a.j - a.l * ft_atoi(a.tab[a.j][a.i]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
				//
				// a.Xf = a.k *((a.i) - a.x/2) + (2000 - a.x) / 2 + a.rightleft;
				// a.Yf = a.k *((a.j - 1) - a.l * ft_atoi(a.tab[a.j - 1][a.i]) - a.y/2) + (1000 - a.y) / 2 + a.updown;
				// //printf("(%.0f,%.0f,%s) - (%.0f,%.0f,%s)\n",a.Xi, a.Yi, a.tab[a.j][a.i], a.Xf, a.Yf, a.tab[a.j+1][a.i]);
				// ft_mlx_line(a.Xi, a.Yi, a.Xf, a.Yf, &a);
			}
			//	if ((int)a.j % 100)
			a.i++;
		}
		a.j++;
		//a.j += 0.01;
	}
	mlx_key_hook(a.win, my_key_funct, &a);
	mlx_loop(a.mlx);
	return (a);
}



t_env ft_xyz(t_env e)
{
	char **tmp;
	//printf("debut de xyzi=%d\tj=%d\tx=%d\ty=%d\n", e.i, e.j, e.x, e.y);
	tmp = NULL;
	e.i = 0;
	e.j = -1;
	if (!(e.tab = (char***)malloc(sizeof(char*) * e.y)))
		exit (0);
	while (e.j++ < e.y-1)
	{
		tmp = ft_strsplit(e.str[e.j], ' ');
		if (!(e.tab[e.j] = (char**)malloc(sizeof(char*) * e.x)))
			exit (0);
		e.i = 0;
		while (tmp[e.i])
		{
			e.tab[e.j][e.i] = (char*)malloc(sizeof(char*)*ft_strlen(tmp[e.i]));
			e.tab[e.j][e.i] = ft_strdup(tmp[e.i]);
			e.i++;
		}
	}
	return(e);
}



/*
 **on obtient un e int **grid avec la map
 ** i et j sont les longueur largeur max
 **
 */

static t_env ft_parse(char **str)
{
	int fd;
	int a;
	char *line;
	int   ret;
	t_env e;
	//int i;

	e.x = 0;
	a = 0;
	e.y = 0;
	fd = 0;
	if ((fd = open(*str, O_RDONLY)) == -1)
		exit (0);
	while ((ret = get_next_line(fd, &line)) > 0)
		e.y++;
	e.str= (char**)malloc(sizeof(char*) * e.y);
	if ((fd = open(*str, O_RDONLY)) == -1)
		exit (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		e.str[a] = *(char**)malloc(sizeof(char*) * ft_strlen(line));
		e.str[a] = ft_strdup(line);
		e.x = ft_strnb(line, ' ');
		a++;
	}
	close (fd);
	//i = -1;
	//while(i++ < a)
	//	ft_putendl(e.str[i]);
	e = ft_xyz(e);

	//  ft_putnbr(e.grid[3][3]);
	ft_mapping(e);
	return (e);
}



/*
 **j'envoie le fichier .fdf a decoder a
 **void *mlx;
 **void *win;//identifiant de la fenetre pour savoir sur laquelle on travaille
 */

int	main(int argc, char **argv)
{
	int fd;
	int a;
	t_env e;

	a = 0;
	e.y = 0;
	fd = 0;
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return (0);
		ft_initval();

		e = ft_parse(&argv[1]);

	}
	return (0);
}
