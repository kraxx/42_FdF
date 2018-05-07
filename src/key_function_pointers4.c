/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function_pointers4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:08:41 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:08:41 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_fp_numpad_2(t_m *m, int press)
{
	m->togs->numpad_2 = press ? 1 : 0;
}

void	key_fp_numpad_4(t_m *m, int press)
{
	m->togs->numpad_4 = press ? 1 : 0;
}

void	key_fp_numpad_6(t_m *m, int press)
{
	m->togs->numpad_6 = press ? 1 : 0;
}

void	key_fp_numpad_8(t_m *m, int press)
{
	m->togs->numpad_8 = press ? 1 : 0;
}
