#include "libft/stack_files/stack.h"
#include "push_swap.h"

static const char	*const error_mess[4] = {"UNKNOW ERROR", "ERROR", \
	"[•] Parse ERROR", "[•] Stack Error"};

void	delete_content(void *content)
{
	free(content);
	content = NULL;
}

void	spawn_error_message(const char *message)
{
	int	len;

	len = ft_strlen(message);
	write(2, message, len);
}

void	select_error(t_err_code code)
{
	int	size;

	size = sizeof(error_mess) / sizeof(error_mess[0]);
	if (code >= size )
		spawn_error_message(error_mess[0]);
	else
		spawn_error_message(error_mess[code]);	
}

void	delete_data(t_data *d)
{
	if (d->ordlist != NULL)
		free(d->ordlist);
	if (d->toorder != NULL)
		free(d->ordlist);
	if (d->A != NULL)
		delete_stack(&d->A, delete_content);	
	if (d->B != NULL)
		delete_stack(&d->B, delete_content);

}

void	error(t_data *d)
{
	t_err_code error;

	error = UNKNOWN;
	if (d->A == NULL || d->B == NULL)
		error = STACK;
	else if (d->ordlist == NULL || d->toorder == NULL)
		error = PARSE;
	delete_data(d);	
	select_error(error);
}

