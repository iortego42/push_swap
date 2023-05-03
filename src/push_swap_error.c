/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:53 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/03 18:45:01 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*error_mess[ERROR + 1] = { 
	"\033[35mUndefined\033[0m\n", 
	"Unclassified\n", 
	"Parsing\n", 
	"Stack\n", 
	"Element\n", 
	"Wrong Input\n", 
	"Malloc\n", 
	"No element founded\n",
	"Empty stack\n",
	"No content\n",
	"Ordering list\n",
		
	"ERROR\n",
};

void	delete_content(void *content)
{
	if (content == NULL)
		return ((void)"42Madrid");
	free(content);
}

void	spawn_error_message(const char *message)
{
	if (ft_strncmp(message, "ERROR", 5))
		ft_putstr_fd("\033[33;1m[•]\033[31m ERROR:\033[0m ", 2);
	ft_putstr_fd((char *)message, 2);
}

void	select_error(t_err_code code)
{
	int	size;

	size = sizeof(error_mess) / sizeof(error_mess[0]);
	if ((int)code >= size )
		spawn_error_message(error_mess[UNKNOWN]);
	else
		spawn_error_message(error_mess[code]);	
}

void	delete_data(t_data *d)
{
	if (d->ordlist != NULL)
		free(d->ordlist);
	if (d->toorder != NULL)
		free(d->toorder);
	if (d->A != NULL)
		delete_stack(&d->A, delete_content);	
	if (d->B != NULL)
		delete_stack(&d->B, delete_content);
}

t_err_code	error(t_data *d, t_err_code error)
{
	if (error == OK)
	{
		error = UNKNOWN;
		if (d->A == NULL || d->B == NULL)
			error = STACK;
		else if (d->ordlist == NULL || d->toorder == NULL)
			error = PARSE;
	}
	delete_data(d);
	select_error(error);
	return (error);
}

