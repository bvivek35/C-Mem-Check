#include <stdio.h>
#include <stdlib.h>

#include "my_list.h"
#include "my_mem_check.h"

/*
	Global variables :
		A list to hold all heap allocated variables.
		An exit function that is executed just before main() exits.
			This will contain cleanup and reporting the output.
*/
list_t *__allocated = 0;

void __at_exit();


int is_valid_d(void *ptr, int off)
{
	//TO-DO
	return 0;	
}

/*
	The safer version of malloc.
	This adds the pointer allocated to the list for tracking purposes
	return the pointer just as malloc would.
	
	When the call to malloc is the first call intercepted, we need to initialize the list and also register the _-at_exit function to run upon termination of main().
*/
void *my_malloc_d(size_t size, int line_no, const char *file)
{
	if (!__allocated) {
		init_list(&__allocated);
		atexit(__at_exit);
	}
	
	void *ptr = malloc(size);
	add_to_list(__allocated, ptr, size, line_no, file);
	
	return ptr;
}

/*
	This will check if the given pointer was allocated or not.
	If it was not allocated, it will print the file and line no. of the call to free in the source.
	It will then proceed with execution as if that call never happened.
*/
void my_free_d(void *ptr, int line_no, const char *file)
{
	if (!is_in_list(__allocated, ptr)) {
		printf("ptr NOT ALLOCATED.\n"
			"File : %s\nLine : %d\nPTR : %p\n", file, line_no, ptr);
		printf("-------------------------------------\n");
	} else {
		free(ptr);
		remove_from_list(__allocated, ptr);
	}
}


/*
	Exit function.
	called just after main() exits and before control returns to the pgm invoker.
*/
void __at_exit()
{
	if (is_empty_list(__allocated)) {
		printf("No Leaks !\n");
	} else {
		printf("Leaked Memory: \n\n");
		display(__allocated);
	}
	
	cleanup_list(__allocated);
}
