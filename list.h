#ifndef LIST_H
#define LIST_H

typedef struct list {
	int elem;
	struct list *next;
	struct list *prev;
} list;

list *list_init(int *arr, int size);

void list_append(int num, list *header);

int list_pop(int index, list *header);

void list_delete(int num, list *header);

void list_print(list *header);

#endif
