#include <stdio.h>
#include <stdlib.h>

#include "my_list.h"

int main()
{
	list_t *l1;
	init_list(&l1);

	add_to_list(l1, (void *)12, (size_t)21);
//	add_to_list(l1, (void *)14, (size_t)20);

//	remove_from_list(l1, (void *)12);
//	remove_from_list(l1, (void *)14);

//	printf("%d\n", is_empty_list(l1));

	display(l1);	

//	printf("%d\n", is_empty_list(l1));

	return 0;
}
