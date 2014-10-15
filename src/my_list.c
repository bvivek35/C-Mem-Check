#include <stdio.h>
#include <stdlib.h>

#include "my_list.h"


void init_list(list_t **l)
{
	*l = malloc(sizeof**l);
	(*l)->__head = 0;
}

void add_to_list(list_t *l, const void *ptr, size_t size, int line_no)
{
	if (l == 0)
		return (void)printf("List Not Initialized !\n");

	__node_t *temp;
	temp = malloc(sizeof *temp);

	temp->__ptr = ptr;
	temp->__size = size;
	temp->__line_no = line_no;
	temp->__link = l->__head;
	l->__head = temp;
}

void remove_from_list(list_t *l, const void *ptr)
{
	if (l == 0)
		return (void)printf("List Not Initialized !\n");

	__node_t *prev = 0;
	__node_t *pres = l->__head;
	__node_t *temp;
	
	while (pres != 0 && pres->__ptr != ptr) {
		prev = pres;
		pres = pres->__link;
	}
	
	if (prev == 0) { //remove first entry
		if (pres != 0) { //check if there is a first entry
			temp = pres;
			l->__head = pres->__link;
			free(temp);
		}		
	} else { //middle or end
		if (pres != 0) { //check for match
			prev->__link = pres->__link;
			free(pres);
		}			
	}
}

int is_in_list(const list_t *l, const void *ptr)
{
	if (l == 0)
		return printf("List Not Initialized !\n"), 0;

	__node_t *temp;
	for (temp = l->__head; temp; temp = temp->__link)
		if (temp->__ptr == ptr)
			return 1;
	
	return 0;
}

void display(const list_t *l)
{
	if (l == 0)
		return (void)printf("List Not Initialized !\n");

	__node_t *temp;
	for (temp = l->__head; temp; temp = temp->__link)
		printf("\t%p\t%zd\t%d\n", temp->__ptr, temp->__size, temp->__line_no);
}

int is_empty_list(const list_t *l)
{
	return l == 0 || l->__head == 0;
}

void cleanup_list(list_t *l)
{
	if (l == 0)
		return (void)printf("List Not Initialized !\n");
	
	__node_t *curr = l->__head;
	if (curr != 0) {
		__node_t *next = curr->__link;
		do {
			next = curr->__link;
			free(curr);
			curr = next;
		} while (next != 0);
	}
	free(l);
}
