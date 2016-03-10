#include "../container.h"
#include "gtest/gtest.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Create funclion
TEST(Create, List)
{
  List* p = list_create();
  EXPECT_TRUE(p);
  Iter it_begin = p->m->begin(p);
  Iter it_end = p->m->end(p);
  EXPECT_FALSE(p->m->get(it_begin));
  EXPECT_FALSE(p->m->get(it_end));
  EXPECT_TRUE(p->m->iter_zeroEqual(it_begin));
  EXPECT_TRUE(p->m->iter_zeroEqual(it_end));
}

//delete elements
TEST(Delete, List)
{
    int N = 200;
    List* p = list_create();
    EXPECT_TRUE(p);
    Iter it = p->m->begin(p);
    EXPECT_TRUE(&it);
    EXPECT_EQ(p->m->elemDelete(&it), -1);
    p->m->iter_insert(&it, &N);
    EXPECT_EQ(p->m->get(it), &N);

    p->m->iter_insert(&it, (void*)201);
    EXPECT_EQ((int*)(p->m->get(it)), (int*)201);

    EXPECT_FALSE(p->m->elemDelete(&it));
    EXPECT_EQ(p->m->get(it), &N);
    EXPECT_FALSE(p->m->elemDelete(&it));
    EXPECT_EQ(p->m->elemDelete(&it), -1);
}
//InsertTo function
TEST(iterInsert, List)
{
  List* p = list_create();
  EXPECT_TRUE(p);
  Iter it_begin = p->m->begin(p);
  Iter it_end = p->m->end(p);
  EXPECT_FALSE(p->m->get(it_begin));
  EXPECT_FALSE(p->m->get(it_end));
  p->m->iter_insert(&it_begin, (void*)2);
  EXPECT_EQ(p->m->get(it_begin), (void*)2);
  p->m->iter_insert(&it_begin, (char*)"azaza");
  EXPECT_STREQ((char*)(p->m->get(it_begin)), "azaza");
  void* pointer = (void*)0x321;
  p->m->iter_insert(&it_begin, pointer);
  EXPECT_EQ(p->m->get(it_begin), pointer);
}


//BubbleSort as a test of several functions
#define N 1050

TEST(bubbleSort, listInsertTo)
{
  List* p1 = list_create();

  EXPECT_TRUE(p1);

  int array[N] = { };
	for (int i = 0; i < N; i++) {
		array[i] = rand() % 20;
	}

  Iter it_begin = p1->m->begin(p1);
  Iter it_end = p1->m->end(p1);

  for (int i = 0; i < N; i++) {
		EXPECT_EQ(p1->m->iter_insert(&it_begin, (void *) (array + i)), 0);
    EXPECT_EQ(p1->m->iter_insert(&it_end, (void *) (array + i)), 0);
	}

for(int i = 0; i < N; i++){
  for(int j = i; j < N; j++){
    if(array[i] > array[j]){
      int buf = array[i];
      array[i] = array[j];
      array[j] = buf;}
    }
  }

 for (Iter i = p1->m->begin(p1); !p1->m->iter_zeroEqual(i);
       p1->m->iter_next(&i)) {
    for (Iter j = i; !p1->m->iter_zeroEqual(j);
         p1->m->iter_next(&j)) {
      if (*((int *) p1->m->get(i)) >
          *((int *) p1->m->get(j))) {
        p1->m->iter_swap(&i, &j);
      }
    }
  }

Iter j = p1->m->begin(p1);
for(int i = 0; i < N; i++){
  EXPECT_EQ(array[i], *((int *) p1->m->get(j)));
  p1->m->iter_next(&j);
  EXPECT_EQ(array[i], *((int *) p1->m->get(j)));
  p1->m->iter_next(&j);
}
}

TEST(bubbleSort, listInsertToBeginAndEnd){
  List* p1 = list_create();
  List* p2 = list_create();
  EXPECT_TRUE(p1);
  EXPECT_TRUE(p2);

  int array[N] = { };
	for (int i = 0; i < N; i++) {
		array[i] = rand() % 20;
	}
  for (int i = 0; i < N; i++) {
		EXPECT_EQ(p1->m->insertToEnd(p1, (void *) (array + i)), 0);
    EXPECT_EQ(p2->m->insertToBegin(p2, (void *) (array + i)), 0);
	}

  for(int i = 0; i < N; i++){
    for(int j = i; j < N; j++){
      if(array[i] > array[j]){
        int buf = array[i];
        array[i] = array[j];
        array[j] = buf;}
      }
    }

   for (Iter i = p1->m->begin(p1); !p1->m->iter_zeroEqual(i);
         p1->m->iter_next(&i)) {
      for (Iter j = i; !p1->m->iter_zeroEqual(j);
           p1->m->iter_next(&j)) {
        if (*((int *) p1->m->get(i)) >
            *((int *) p1->m->get(j))) {
          p1->m->iter_swap(&i, &j);
        }
      }
    }

    for (Iter i = p2->m->begin(p2); !p2->m->iter_zeroEqual(i);
          p2->m->iter_next(&i)) {
       for (Iter j = i; !p2->m->iter_zeroEqual(j);
            p2->m->iter_next(&j)) {
         if (*((int *) p2->m->get(i)) >
             *((int *) p2->m->get(j))) {
           p2->m->iter_swap(&i, &j);
         }
       }
     }

  Iter j = p1->m->begin(p1);
  Iter k = p2->m->begin(p2);
  for(int i = 0; i < N; i++){
     EXPECT_EQ(array[i], *((int *) p1->m->get(j)));
     EXPECT_EQ(array[i], *((int *) p1->m->get(j)));
     p1->m->iter_next(&j);
     EXPECT_EQ(array[i], *((int *) p2->m->get(k)));
     p2->m->iter_next(&k);
   }

   k = p2->m->begin(p2);
   for (Iter i = p1->m->begin(p1); !p1->m->iter_zeroEqual(i);
         p1->m->iter_next(&i)) {
           EXPECT_EQ(*((int *) p2->m->get(k)), *((int *) p1->m->get(i)));
           p2->m->iter_next(&k);
         }

}

#undef N
