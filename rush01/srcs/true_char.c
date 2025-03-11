#include "libft.h"

int	true_char(char c)
{
	if (c == ' ')
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
