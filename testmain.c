
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int len;
	int len2;

	len = ft_printf("[%010s]", "abcdef");
	printf("\n");
	len2 = printf("[%010s]", "abcdef");
	printf("\n");
	printf("len %d, len2 %d", len, len2);
	return (0);
}
