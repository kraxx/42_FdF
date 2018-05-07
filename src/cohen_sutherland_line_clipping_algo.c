/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland_line_clipping_algo.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:49:43 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:49:44 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Calculates pixels that lay outside the viewing frame and discards them to
** reduce wasted calculations. Uses 4 bits to determine coordinates of a
** 3x3 grid representing the visible viewing frame as the center of the grid.
*/

#include "fdf.h"

static int	compute_code(double x, double y)
{
	int code;

	code = 0;
	if (x < 0)
		code |= 1;
	if (x > WIN_WIDTH - 1)
		code |= 2;
	if (y < 0)
		code |= 4;
	if (y > WIN_HEIGHT - 1)
		code |= 8;
	return (code);
}

static void	cohen_sutherland_util2(t_cs *cs, t_coor *c)
{
	if (cs->code1)
	{
		c->x1 = cs->ret_x;
		c->y1 = cs->ret_y;
		cs->code1 = compute_code(c->x1, c->y1);
	}
	else
	{
		c->x2 = cs->ret_x;
		c->y2 = cs->ret_y;
		cs->code2 = compute_code(c->x2, c->y2);
	}
}

static void	cohen_sutherland_util(t_cs *cs, t_coor *c)
{
	cs->ret_code = cs->code1 ? cs->code1 : cs->code2;
	if (cs->ret_code & 8)
	{
		cs->ret_x = c->x1 + (c->x2 - c->x1) *
			(WIN_HEIGHT - 1 - c->y1) / (c->y2 - c->y1);
		cs->ret_y = WIN_HEIGHT - 1;
	}
	else if (cs->ret_code & 4)
	{
		cs->ret_x = c->x1 + (c->x2 - c->x1) * (0 - c->y1) / (c->y2 - c->y1);
		cs->ret_y = 0;
	}
	else if (cs->ret_code & 2)
	{
		cs->ret_x = WIN_WIDTH - 1;
		cs->ret_y = c->y1 + (c->y2 - c->y1) *
			(WIN_WIDTH - 1 - c->x1) / (c->x2 - c->x1);
	}
	else if (cs->ret_code & 1)
	{
		cs->ret_x = 0;
		cs->ret_y = c->y1 + (c->y2 - c->y1) * (0 - c->x1) / (c->x2 - c->x1);
	}
}

void		cohen_sutherland(t_img *img, t_coor c)
{
	t_cs cs;

	cs.code1 = compute_code(c.x1, c.y1);
	cs.code2 = compute_code(c.x2, c.y2);
	while (1)
	{
		if (!cs.code1 && !cs.code2)
		{
			bresenham(img, c);
			break ;
		}
		else if (cs.code1 & cs.code2)
			break ;
		else
		{
			cohen_sutherland_util(&cs, &c);
			cohen_sutherland_util2(&cs, &c);
		}
	}
}
