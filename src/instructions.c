/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 20:40:40 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 20:40:41 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	w_i(char *key, char *text, int spaces)
{
	int i;

	i = -1;
	ft_putstr("[36m");
	ft_putstr(key);
	ft_putstr("[0m");
	while (++i < spaces)
		ft_putchar(' ');
	ft_putstr(text);
	ft_putchar('\n');
}

void		write_legend(void)
{
	ft_putstr("\nKEYS:\n\n");
	w_i("[↑][↓][←][→][LEFT CLICK]", "Translate object", 8);
	w_i("NUMPAD[↑][↓][←][→][RIGHT CLICK]", "Rotate object around X/Y axes", 1);
	w_i("[WHEEL CLICK]", "Rotate object around mouse point", 19);
	w_i("NUMPAD[7][9]", "Rotate object around Z axis", 20);
	w_i("[+][-][WHEEL UP/DOWN]", "Zoom in/out", 11);
	w_i("[*]", "Switch colour pulser", 29);
	w_i("[/]", "Toggle colour pulser on/off", 29);
	w_i("NUMPAD[0]", "Reset object state", 23);
	w_i("[FN][DEL]", "Skew X coordinates", 23);
	w_i("[HOME][END]", "Skew Y coordinates", 21);
	w_i("[PAGE UP][PAGE DOWN]", "Adjust Z coordinates (Don't do this)", 12);
	w_i("[ESC]", "Exit program", 27);
}

int			write_error(void)
{
	ft_putendl("error; usage: ./fdf [map.fdf]");
	return (1);
}
