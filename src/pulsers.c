/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:17:18 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:17:19 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Custom pulsing patterns; slowly adjusts hex values
*/

void	pulse_dark_rgb(t_xyz **grid, size_t x, size_t y)
{
	if (grid[y][x].c >= 0xffffff)
		grid[y][x].c = 0;
	else if (grid[y][x].c == 0xffff)
		grid[y][x].c = 0x010000;
	else if (grid[y][x].c == 0xff)
		grid[y][x].c = 0x0100;
	else
	{
		if (grid[y][x].c > 0xffff)
			grid[y][x].c += 0x010000;
		else if (grid[y][x].c > 0xff)
			grid[y][x].c += 0x0100;
		else
			grid[y][x].c += 1;
	}
}

/*
** Yellow -> Magenta -> Teal -> Yellow
*/

void	pulse_pastel(t_xyz **grid, size_t x, size_t y)
{
	if (((grid[y][x].c ^ 0xffff00) < 0x100) &&
			(grid[y][x].c & 0xff) > 0)
		grid[y][x].c -= 1;
	else if ((grid[y][x].c ^ 0xff0000) < 0x10000 &&
			(grid[y][x].c & 0xff) < 0xff)
		grid[y][x].c -= 0xff;
	else if ((grid[y][x].c & 0xff0000) &&
			(grid[y][x].c & 0xff00) < 0xff00)
		grid[y][x].c -= 0xff00;
	else if ((grid[y][x].c & 0xff0000) < 0xff0000)
		grid[y][x].c += 0xffff;
	else
		grid[y][x].c = 0xffffff;
}

/*
** Yellow -> Red -> Black -> Blue -> Teal -> White -> Yellow
*/

void	pulse_groovy(t_xyz **grid, size_t x, size_t y)
{
	if (((grid[y][x].c ^ 0xffff00) < 0x100) &&
			(grid[y][x].c & 0xff) > 0)
		grid[y][x].c -= 1;
	else if ((grid[y][x].c ^ 0xff0000) < 0x10000 &&
			(grid[y][x].c & 0xff00) > 0)
		grid[y][x].c -= 0x0100;
	else if (!(grid[y][x].c & 0xffff) && (grid[y][x].c > 0))
		grid[y][x].c -= 0x10000;
	else if ((grid[y][x].c) < 0xff)
		grid[y][x].c += 1;
	else if ((grid[y][x].c) < 0xffff)
		grid[y][x].c += 0x100;
	else if (grid[y][x].c < 0xffffff)
		grid[y][x].c += 0x10000;
	else
		grid[y][x].c = 0xffffff;
}

void	pulse_wrapper(t_xyz **grid, size_t x_count, size_t y_count,
						void (pulser(t_xyz**, size_t, size_t)))
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < y_count)
	{
		x = -1;
		while (++x < x_count)
			if (!grid[y][x].c_lock)
				pulser(grid, x, y);
	}
}
