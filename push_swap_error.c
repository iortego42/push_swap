#include "push_swap.h"

const static char	*error_mess[3] = {"UNKNOW ERROR", "ERROR", NULL};


void	spawn_error_message(const char *message)
{
	int	len;

	len = ft_strlen(message);
	write(2, message, len);
}

void	select_error(t_err_code code)
{
	int	index;

	index = 0;
	while (error_mess[index] != NULL)
		index++;
	if (code >= index )
		spawn_error_message(error_mess[0]);
	else
		spawn_error_message(error_mess[code]);	
}

void	delete_content(void *content)
{
	free(content);
	content = NULL;
}
