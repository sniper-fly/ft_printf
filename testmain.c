
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int len;
	int len2;

	len = ft_printf("[%0*.*s]", 10, 3, NULL);
	printf("\n");
	len2 = printf("[%0*.*s]", -10, 3, NULL);
	// printf("[%*c]", 10, ' ');
	printf("\n");
	printf("%d", len);
	return (0);
}