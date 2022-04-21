
#include <unistd.h>

int	ft_sqrt(int nb)
{
	int		factor;
	int		result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	factor = 1;
	result = factor;
	if (nb > 0)
	{
		while (result <= nb)
		{
			if (result == nb)
				return (factor);
			else if (result >= 46341)
				return (0);
			factor++;
			result = factor * factor;
		}
	}
	return (0);
}
