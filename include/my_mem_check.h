#ifndef MY_MEM_CHECK_H
#define MY_MEM_CHECK_H


/* 
	Macros to get my_malloc to transfer call information to the implementation file.
	Note :
		The client shall call malloc and free only.
		While compiling he can provide macro definitions using
			-Dmalloc=my_malloc -Dfree=my_free
		These preprocessor directives at compilation time will replace the calls of malloc with my_malloc and free with my_free.
		Later on the preprocessor will expand the below macros that will contain line no and other useful information.
*/

#define my_malloc(x) my_malloc_d(x, __LINE__, __FILE__)
#define my_free(x) my_free_d(x, __LINE__, __FILE__)


/*
TO-DO
*/
#define is_valid(x) is_valid_d(x, sizeof(*x))

int is_valid_d(void *ptr, int off);


/*
	Actual functions implemented.
*/
void *my_malloc_d(size_t size, int line_no, const char *file);
void my_free_d(void *ptr, int line_no, const char *file);

#endif
