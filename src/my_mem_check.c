#include <stdio.h>
#include <stdlib.h>

#include "my_list.h"

#include "my_mem_check.h"



list_t *__allocated = 0;


void __at_exit();

int is_valid_d(void *ptr, int off)
{
	//TO-DO
	return 0;	
}

void *my_malloc_d(size_t size, int line_no)
{
	if (!__allocated) {
		init_list(&__allocated);	
		atexit(__at_exit);
	}
	
	void *ptr = malloc(size);
	add_to_list(__allocated, ptr, size, line_no);
	
	return ptr;
}

void my_free_d(void *ptr, int line_no)
{
	if (!is_in_list(__allocated, ptr)) {
		printf("ptr NOT ALLOCATED.\n"
				"Line : %d\nPTR : %p\n", line_no, ptr);
	} else {
		free(ptr);
		remove_from_list(__allocated, ptr);
	}
}

void __at_exit()
{
	if (is_empty_list(__allocated)) {
		printf("All Heap Clear !\n");
	} else {
		printf("Leaked : \n\n");
		display(__allocated);
	}
	
	cleanup_list(__allocated);
}
