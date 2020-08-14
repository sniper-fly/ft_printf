
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int len;
	len = ft_printf("[%0*.*s]", -10, -3, "abcd");
	printf("\n");
	len = printf("[%0*.*s]", -10, -3, "abcd");
	// printf("[%*c]", 10, ' ');
	printf("\n");
	printf("%d", len);
	return (0);
}