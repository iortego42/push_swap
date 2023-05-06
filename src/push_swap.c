/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:33 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/06 19:03:57 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void pepe(){
	system("leaks push_swap");
}
int main(int argc, char **argv)
{
	atexit(pepe);
	t_data		data;
	t_err_code	status;

	init(&data);
	status = analize_input(argv, argc, &data);
	if (status != OK)
		return (error(&data, status));
	status = charge_stack_A(&data);
	if (status != OK)
		return (error(&data, status));
	status = algorithm(&data);
	if (status != OK)
		return (error(&data, status));
	return (OK);
}
