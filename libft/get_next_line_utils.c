#include "libft.h"

int	all_error_free(char **s1, char **s2)
{
	free(*s1);
	*s1 = NULL;
	free(*s2);
	*s2 = NULL;
	return (ERROR);
}

int	error_free(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (ERROR);
}
