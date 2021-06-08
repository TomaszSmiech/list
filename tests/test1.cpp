#include<gtest/gtest.h>
#include "../src/list.h"

TEST(TEST,tc1)
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(10);
	l.push_back(22);
	ASSERT_EQ("1 2 10 22 ",l.get_list());

}

TEST(TEST,tc2)
{
	list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(10);
	l.push_front(22);
	ASSERT_EQ("22 10 2 1 ",l.get_list());

}

TEST(TEST,tc3)
{
	list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(10);
	l.push_front(22);
	l.reverse();
	ASSERT_EQ("1 2 10 22 ",l.get_list());

}

TEST(TEST,tc4)
{
	list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(10);
	l.push_front(22);
	l.insert(100,2);
	ASSERT_EQ("22 10 2 100 1 ",l.get_list());

}

TEST(TEST,tc5)
{
	list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(10);
	l.push_front(22);
	l.insert(100,2);
	ASSERT_EQ("22 10 2 100 1 ",l.get_list());

}
