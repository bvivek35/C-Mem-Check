#ifndef MY_MEM_CHECK_H
#define MY_MEM_CHECK_H

#define my_malloc(x) my_malloc_d(x, __LINE__, __FILE__)
#define my_free(x) my_free_d(x, __LINE__, __FILE__)

#define is_valid(x) is_valid_d(x, sizeof(*x))

int is_valid_d(void *ptr, int off);

void *my_malloc_d(size_t size, int line_no, const char *file);
void my_free_d(void *ptr, int line_no, const char *file);

#endif
