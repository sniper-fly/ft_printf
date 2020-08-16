
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int len;
	int len2;

	len = ft_printf("[%0*.*c]", 13, 10, 'a');
	printf("\n");
	len2 = printf("[%0*.*c]", 13, 10, 'a');
	printf("\n");
	printf("len %d, len2 %d", len, len2);
	return (0);
}

// #include <stdio.h>
// #include <limits.h>
// #include <unistd.h>

// int		main(void)
// {
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		printf("%x", i);
// 		printf("\n");
// 	}

// 	return (0);
// }