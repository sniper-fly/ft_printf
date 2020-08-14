
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int len;
	len = ft_printf("[%c]", 'a');
	printf("\n");
	printf("%d", len);
	return (0);
}