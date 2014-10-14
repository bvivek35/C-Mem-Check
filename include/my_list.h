typedef struct __node {
	const void *__ptr;
	size_t __size;
	int __line_no;
	struct __node *__link;
} __node_t;

typedef struct __list {
	__node_t *__head;	
} list_t;


void init_list(list_t **);
void cleanup_list(list_t *);

void add_to_list(list_t *, const void *, size_t __size, int __line_no);
void remove_from_list(list_t *, const void *);

int is_in_list(const list_t *, const void *);
int is_empty_list(const list_t *);

void display(const list_t *);
