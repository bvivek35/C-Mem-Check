#ifndef MY_LIST_H
#define MY_LIST_H


/*
	node for the linked list.
	fields :
		pointer to hold pointer value.
		size allocated with the pointer
		line no of call in src file
		src file name and location
		
		a link to the next node.
*/
typedef struct __node {
	const void *__ptr;
	size_t __size;
	int __line_no;
	const char *__file_name;
	struct __node *__link;
} __node_t;


/*
	list.
	Use pointer to list_t in client.
*/
typedef struct __list {
	__node_t *__head;	
} list_t;

/*
	Supported Interface :
		
		initialization and cleanup
		
		basic addition & removal operations
		
		Checking operations
		
		Displaying the list
*/
void init_list(list_t **list_ptr);
void cleanup_list(list_t *l);

void add_to_list(list_t *l, const void *ptr, size_t size, 
			int line_no, const char *file_name);
void remove_from_list(list_t *l, const void *ptr);

int range_in_list(const list_t *l, const void *ptr, size_t offset);
int is_in_list(const list_t *l, const void *ptr);
int is_empty_list(const list_t *l);

void display(const list_t *l);

#endif
