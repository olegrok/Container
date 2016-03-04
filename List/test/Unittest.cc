#include "../container.h"
#include "gtest/gtest.h"
TEST(Create, List)
{
  List* p = list_create();
  EXPECT_TRUE(p);
  Iter it_begin = p->m->begin(p);
  Iter it_end = p->m->end(p);
  EXPECT_FALSE(p->m->get(it_begin));
  EXPECT_FALSE(p->m->get(it_end));
}

TEST(Insert, List)
{
  List* p = list_create();
  EXPECT_TRUE(p);
  Iter it_begin = p->m->begin(p);
  Iter it_end = p->m->end(p);
  EXPECT_FALSE(p->m->get(it_begin));
  EXPECT_FALSE(p->m->get(it_end));
  p->m->iter_insert(&it_begin, (void*)2);
  EXPECT_EQ(p->m->get(it_begin), (void*)2);
}
