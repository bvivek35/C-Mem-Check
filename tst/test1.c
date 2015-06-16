#include <stdio.h>
#include <stdlib.h>

#include "mem_check.h"

int main()
{

	int *p;
#if 0	
	p = malloc(30 * sizeof *p);

	p = malloc(25 * sizeof *p);	
#endif

	
#if 0
	free(calloc(20, 90));
	calloc(20, sizeof *p);
#endif
#if 0
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

#if 1
	p = malloc(10 * sizeof(int));
	printf("is_valid : %d\n", is_valid(p));
	free(p);
#endif

	return 0;
}
