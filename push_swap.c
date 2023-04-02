#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data		*data;
	t_err_code	status;

	init(data);
	status = analize_input(argv, argc, data);
	if (status != OK)
		return (error(data, status));
	status = algorithm(data);
	if (status != OK)
		return (error(data, status));
	return (OK);
}
