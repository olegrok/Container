#ifndef MYLIST_H
#define MYLIST_H

typedef struct listElem Elem;

typedef
    struct list {
	struct container_methods *m;
	Elem *start;
} List;

typedef
    struct iterator {
	void *indx;
	void *obj;
} Iter;


List *list_create();

void list_delete(void *p);
Iter list_iter_begin(void *p);
Iter list_iter_end(void *p);
int list_insertToBegin(void *p, void *data);
int list_insertToEnd(void *p, void *data);

void list_iter_prev(Iter * p);
void list_iter_next(Iter * p);
void list_insertTo(Iter * p, void *data);
void *list_iter_get(Iter p);
int list_iter_zeroEqual(Iter p);
void list_swap(Iter * p, Iter * q);

#endif
