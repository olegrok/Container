/*
list_next
list_get
*next->list_next();
*get_list_get();
*begin...
list_create()
{

	m = malloc();
	m->next=list_next();
	begin=
}

вывод
вставка\удаление
сортировка

	create
	delete
	insert ()
	delet_elem
	get_elem

logo model library
OplenGL
SDL
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "container.h"

extern struct container_methods list_m;

typedef
    struct listElem {
	void *data;
	struct listElem *prev;
	struct listElem *next;
} Elem;

Elem 	*add_elem();
void 	delete_elem(Elem * p);
void 	delete_allElems(Elem * p);
int 	list_iter_zeroEqual(Iter p);
int 	list_iter_next(Iter * p);
int 	list_iter_prev(Iter * p);
Iter 	list_iter_begin(void *p);
Iter 	list_iter_end(void *p);
List 	*list_create();
void 	list_delete(void *p);
int 	list_elem_delete(Iter *p);
int 	list_insertToBegin(void *p, void *data);
void 	list_insertTo(Iter * p, void *data);
int 	list_insertToEnd(void *p, void *data);
void 	list_swap(Iter * it_1, Iter * it_2);
void 	*list_iter_get(Iter p);


Elem *add_elem()
{
	Elem *elem = calloc(1, sizeof(Elem));
	//printf("added elem: %p\n", elem);
	return elem;
}

void delete_elem(Elem * p)
{
	free(p);
	p = NULL;
}

void delete_allElems(Elem * p)
{
	if (p->next != 0)
		delete_allElems(p->next);
	delete_elem(p);
}

int list_iter_prev(Iter * p)
{
	Elem *elem = p->indx;
	if(elem->prev == NULL)
		return -1;
	p->indx = elem->prev;
	return 0;
}

int list_iter_zeroEqual(Iter p)
{
	Elem *elem = p.indx;
	//printf("zeroEqual_elem = %p\n", elem);
	if (elem->next == NULL)
		return 1;
	//printf("zeroEqual_elem->next = %p\n", elem->next);
	//if (p->index->next)
	return 0;
}

int list_iter_next(Iter *p)
{
	//printf("before list_iter_next elem = %p\n", p->indx);
	if(list_iter_zeroEqual(*p))
		return -1;
	Elem *elem = p->indx;
	//printf("wait list_iter_next elem = %p\n", elem->next);
	p->indx = elem->next;
	//printf("after list_iter_next elem = %p\n", p->indx);
	//p->index = p->index->next;
	return 0;
}

Iter list_iter_begin(void *p)
{
	List *l = p;
	Iter it = { l->head, p };
	//Iter *it = calloc(1, sizeof(Iter));
	//it->index = p->start;
	//it->indx = p->start;
	//list_iter_methods(it);
	//printf("it: list_iter_prev %p\n", it->index);
	return it;
}

Iter list_iter_end(void *p)
{
	List *l = p;
	Iter it = {l->head, p};
	//for (; !list_iter_zeroEqual(it); list_iter_next(&it));
	//printf("LOOP ENDED\n");
	//Elem* elem = it->indx;
	//printf("Last: %p\n", it->indx);
	//printf("Last-prev: %p\n", elem->prev);        
	//if(elem != NULL)
	//      printf("Last-next: %p\n", elem->next);
	return it;
}

List *list_create()
{
	List *p = calloc(1, sizeof(List));
	p->head = add_elem();
	p->tail = p->head;
	//printf("it: p->start %p\n", p->start);
	p->head->prev = NULL;
	p->head->next = NULL;
	p->head->data = NULL;
	p->m = &list_m;
	return p;
}

void list_delete(void *p)
{
	List *l = p;
	delete_allElems(l->head);
	free(p);
}

int list_elem_delete(Iter *p)
{
	Elem *buf = p->indx;
	if(buf->prev)
		buf->prev->next = buf->next;
	if(buf->next == NULL)
		return -1;
	buf->next->prev = buf->prev;
	delete_elem(buf);
	list_iter_next(p);
	return 0;
}

int list_insertToBegin(void *p, void *data)
{
	List *l = p;
	//printf("0it: p->start %p\n", l->head);
	Elem *newElem = add_elem();
	if (newElem == NULL)
		return -1;
	newElem->data = data;

	newElem->next = l->head;
	newElem->prev = NULL;
	l->head->prev = newElem;
	l->head = newElem;
	//printf("1it: l->head %p\n", l->head);
	//printf("1it: l->head->next %p\n", l->head->next);
	//printf("1it: l->head->next->prev %p\n", l->head->next->prev);
	return 0;
}

void list_insertTo(Iter *p, void *data)
{
	Elem *newElem = add_elem();
	newElem->data = data;
	//if(p->index->next == NULL)
	Elem *elem = p->indx;
	//printf("start elem %p\n", elem);
	//printf("TOelement %p\n", elem);
	List* l = p->obj;
	if(l->head == p->indx)
	{
		list_insertToBegin(l, data);
		p->indx = l->head;
		return;
	}
	
	elem->prev->next = newElem;
	newElem->prev = elem->prev;
	newElem->next = elem;
	elem->prev = newElem;
	p->indx = newElem;
	printf("end elem %p\n", p->indx);
}

int list_insertToEnd(void *l, void *data)
{
	List *p = l;
	//printf("p->start[%p]->next = %p\n",p->start, p->start->next);
	if (p->head->next == NULL) {
		return list_insertToBegin(p, data);
	}
	Iter it = list_iter_end(p);
	//printf("it: list_iter_end %p\n", it->indx);
	//Elem* elem = it -> indx;
	//printf("it: list_iter_end->next %p\n", elem->next);
	//printf("it: list_iter_end->prev %p\n", elem->prev);
	//list_iter_prev(it);
	//printf("it: list_iter_prev %p\n", it->indx);
	list_insertTo(&it, data);
	//free(it);
	return 0;
}

void list_swap(Iter * it_1, Iter * it_2)
{
	Elem *elem1 = it_1->indx;
	Elem *elem2 = it_2->indx;
	void *data_buf = elem1->data;
	elem1->data = elem2->data;
	elem2->data = data_buf;
	it_1->indx = elem1;
	it_2->indx = elem2;
}

void *list_iter_get(Iter p)
{
	Elem *elem = p.indx;
	return elem->data;
}

