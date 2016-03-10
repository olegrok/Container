#ifndef CONTAINER_H
#define CONTAINER_H
#ifdef __cplusplus
extern "C"  {
#endif

#include "list.h"

typedef struct list List;
typedef struct iterator Iter;
List* list_create();

typedef
    struct container_methods {
	void (*destroy) (void *);
	Iter(*begin) (void *);
	Iter(*end) (void *);
	int (*insertToBegin) (void *, void *);
	int (*insertToEnd) (void *, void *);
	int (*elemDelete) (Iter *);

	int  (*iter_prev) (Iter *);
	int  (*iter_next) (Iter *);
	int (*iter_insert) (Iter *, void *);
	void *(*get) (Iter);
	int (*iter_zeroEqual) (Iter);
	void (*iter_swap) (Iter *, Iter *);

} ContMet;

#ifdef __cplusplus
}
#endif
#endif










//win
