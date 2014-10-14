#include <stdio.h>
#include <stdlib.h>

#include "my_mem_check.h"

int main()
{
	int *p;

#if 1
	free(p);
#endif

#if 0
	p = malloc(200);
	
#endif

#if 0
	p = malloc(sizeof *p);
	free(p);
#endif

#if 0
	p = malloc(sizeof *p);
	free(p);
	free(p);
#endif

#if 0
	p = malloc(sizeof *p);
#endif

#if 0	
	p = calloc(10, sizeof *p);
#endif	

	return 0;
}