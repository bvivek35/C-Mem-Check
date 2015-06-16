#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
	list_t *l1 = 0;
	init_list(&l1);

	add_to_list(l1, (void *)50, (size_t)20, 1, "a.c");
	add_to_list(l1, (void *)12, (size_t)21, 0, "a.c");

//	remove_from_list(l1, (void *)12);
//	remove_from_list(l1, (void *)14);

//	printf("%d\n", is_empty_list(l1));

	display(l1);	
	
	int ptr = 14;
	int off = 50;
	
	printf("%p, %d : %d\n", ptr, off, range_in_list(l1, ptr, off));

//	printf("%d\n", is_empty_list(l1));

	return 0;
}
