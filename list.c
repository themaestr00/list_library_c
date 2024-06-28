#include "list.h"

#include <stdio.h>
#include <stdlib.h>

list *list_init(int *arr, int size) {
    if (size <= 0) {
        return NULL;
    }
    list *header = (list*)malloc(sizeof(list));
    if (!header) {
        fprintf(stderr, "Memory is out");
        exit(1);
    }
    header -> elem = arr[0];
    header -> prev = header -> next = NULL;
    list *p = header;
    for (int i = 1; i < size; i++) {
        p -> next = (list*)malloc(sizeof(list));
        if (!(p -> next)) {
            fprintf(stderr, "Memory is out");
            exit(1);
        }
        p -> next -> elem = arr[i];
        p -> next -> next = NULL;
        p -> next -> prev = p;
        p = p -> next;
    }
    return header;
}

void list_print(list *header) {
    list *p = header;
    while (p) {
        printf("%d ", p -> elem);
        p = p -> next;
    }
    printf("\n");
}