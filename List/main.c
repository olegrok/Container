#include <stdlib.h>
#include <stdio.h>
#define N 5
#include "container.h"


int main()
{
	int k = 0;
	List *myList = CREATE();
	int array[N] = { };
	for (k = 0; k < N; k++) {
		array[k] = rand() % 50;
		printf("a[%d] = %d [%p]\n", k, array[k], &array[k]);
	}

	Iter i = myList->m->begin(myList);
	for (k = 0; k < N; k++) {
		myList->m->iter_insert(&i, (void *) (array + k));
		myList->m->insertToEnd(myList, (void *) (array + k));
	}

	Iter j = i;
	printf("\n\n");
	for (i = myList->m->begin(myList); !myList->m->iter_zeroEqual(i);
			myList->m->iter_next(&i))
		printf("%d\n", *((int *) myList->m->get(i)));
	printf("\n\n");

	//printf("myList->m->iter_next(&i) = %d\n", myList->m->iter_next(&i));
	myList->m->iter_prev(&i);

	//myList->m->iter_prev(&i);
	//myList->m->iter_prev(&i);

	myList->m->elemDelete(&i);

	for (i = myList->m->begin(myList); !myList->m->iter_zeroEqual(i);
	     myList->m->iter_next(&i)) {
		for (j = i; !myList->m->iter_zeroEqual(j);
		     myList->m->iter_next(&j)) {
			if (*((int *) myList->m->get(i)) >
			    *((int *) myList->m->get(j))) {
				myList->m->iter_swap(&i, &j);
			}
		}
	}
	i = myList->m->begin(myList);
	for (; !myList->m->iter_zeroEqual(i); myList->m->iter_next(&i))
		printf("%d\n", *((int *) myList->m->get(i)));
	myList->m->delete(myList);

	return 0;
}
