/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_drawing_algo.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:45:20 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:45:20 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Calculates coordinates of a straight line from point A to point B.
*/

#include "fdf.h"

static void	init_bresenham_values(t_bres *b, t_coor c)
{
	b->dx = fabs(c.x2 - c.x1);
	b->dy = fabs(c.y2 - c.y1);
	b->sx = c.x1 < c.x2 ? 1 : -1;
	b->sy = c.y1 < c.y2 ? 1 : -1;
	b->err = (b->dx > b->dy ? b->dx : -b->dy) / 2;
	b->x1 = c.x1;
	b->y1 = c.y1;
	b->hypo = hypot(b->dx, b->dy);
	b->grad = (int)(b->hypo / (GRADIENT)) > 1 ? (int)(b->hypo / (GRADIENT)) : 1;
}

static void	bresenham_util(t_bres *b, t_coor *c)
{
	b->err2 = b->err;
	if (b->err2 > -b->dx)
	{
		b->err -= b->dy;
		c->x1 += b->sx;
	}
	if (b->err2 < b->dy)
	{
		b->err += b->dx;
		c->y1 += b->sy;
	}
}

void		bresenham(t_img *img, t_coor c)
{
	t_bres b;

	init_bresenham_values(&b, c);
	while (!(((b.sx == -1 && c.x1 <= c.x2) || (b.sx == 1 && c.x1 >= c.x2)) &&
		((b.sy == -1 && c.y1 <= c.y2) || (b.sy == 1 && c.y1 >= c.y2))))
	{
		if (c.c1 == c.c2)
			img->data[(int)c.x1 + (int)c.y1 * img->size / 4] = c.c1;
		else
		{
			b.level = (hypot(c.x1 - b.x1, c.y1 - b.y1) / b.grad);
			img->data[(int)c.x1 + (int)c.y1 * img->size / 4] =
				color_inc(c.c1, c.c2, b.level);
		}
		bresenham_util(&b, &c);
	}
}
