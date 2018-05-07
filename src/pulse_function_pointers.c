/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulse_function_pointers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 20:58:59 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 20:59:00 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_pulse_fp(t_m *m)
{
	m->pulse_fp[0] = &pulse_pastel;
	m->pulse_fp[1] = &pulse_groovy;
	m->pulse_fp[2] = &pulse_dark_rgb;
}
