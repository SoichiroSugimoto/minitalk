#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((0 <= str[i] && str[i] <= 47) || (58 <= str[i] && str[i] <= 127))
			return (0);
		res = res * 10;
		res += (int)str[i] - '0';
		i++;
	}
	return (res * sign);
}
