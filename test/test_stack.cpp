// тесты для стека

#include "stack.h"
#include <gtest.h>
TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> a());
}
TEST(TStack, can_add_elements_to_stack)
{
	TStack<int> a;
	a.push(1);
	EXPECT_EQ(a.see(), 1);
}
TEST(TStack, can_return_size)
{
	TStack<int> a;
	EXPECT_EQ(a.StSize(), 0);
	a.push(1);
	EXPECT_EQ(a.StSize(), 1);
}
TEST(TStack, throws_if_trying_to_get_from_empty_stack)
{
	TStack<int> a;
	ASSERT_ANY_THROW(a.see());
}
TEST(TStack, throw_if_pop_from_empty_stack)
{
	TStack<int> a;
	ASSERT_ANY_THROW(a.pop());
}
TEST(TStack, can_clear_stack)
{
	TStack<int> a;
	a.push(1);
	a.clr();
	EXPECT_EQ(a.StSize(), 0);
}
TEST(TStack, can_push_and_pop_many)
{
	TStack<int> a;
	for (int i = 0; i < 1000; i++) {
		ASSERT_NO_THROW(a.push(i));
	}
	for (int i = 999; i >= 500; i--) {
		EXPECT_EQ(a.pop(), i);
	}
	EXPECT_EQ(a.StSize(), 500);
}
TEST(TStack, can_check_if_empty)
{
	TStack<int> a;
	EXPECT_EQ(a.is_empty(), true);
	a.push(1);
	EXPECT_EQ(a.is_empty(), false);
}