#include "..\mp2-lab3-stack\Stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Stack<char> s(3));
}
TEST(Stack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<char> s(-3));
}

TEST(Stack, can_push_element_to_stack_if_notFull)
{
	Stack<int> s(3);
	ASSERT_NO_THROW(s.push(2));
}
TEST(Stack, cannot_push_element_to_stack_if_full)
{
	Stack<int> s(2);
	s.push(2);
	s.push(4);
	ASSERT_ANY_THROW(s.push(8));
}

TEST(Stack, copy_stack_is_equal)
{
	Stack<int> s1(2);
	s1.push(2);
	s1.push(4);
	Stack<int> s2(s1);
	ASSERT_EQ(s1, s2);
}
TEST(Stack, copy_stack_have_own_memery)
{
	Stack<int> s1(2);
	s1.push(2);
	s1.push(4);
	Stack<int> s2(s1);
	ASSERT_NE(&s1, &s2);
}
TEST(Stack, assign_operator_is_equal)
{
	Stack<int> s1(2);
	s1.push(2);
	s1.push(4);
	Stack<int> s2(5);
	s2 = s1;
	ASSERT_EQ(s1, s2);
}
TEST(Stack, assign_operator_have_own_memery)
{
	Stack<int> s1(2);
	s1.push(2);
	s1.push(4);
	Stack<int> s2(5);
	s2 = s1;
	ASSERT_NE(&s1, &s2);
}

TEST(Stack, can_pop_element_from_stack_if_notEmpty)
{
	Stack<int> s(3);
	s.push(2);
	s.push(4);
	ASSERT_EQ(s.pop(), 4);
}
TEST(Stack, cannot_pop_element_from_stack_if_empty)
{
	Stack<int> s(3);
	ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, test_is_empty_true)
{
	Stack<int> s(3);
	ASSERT_TRUE(s.isEmpty());
}
TEST(Stack, test_is_empty_false)
{
	Stack<int> s(3);
	s.push(2);
	s.push(3);
	ASSERT_FALSE(s.isEmpty());
}

TEST(Stack, test_is_full_true)
{
	Stack<int> s(2);
	s.push(2);
	s.push(3);
	ASSERT_TRUE(s.isFull());
}
TEST(Stack, test_is_full_false)
{
	Stack<int> s(3);
	s.push(2);
	ASSERT_FALSE(s.isFull());
}

TEST(Stack, compare_two_equals_stacks_is_true)
{
	Stack<int> s1(6);
	s1.push(2);
	s1.push(3);
	Stack<int> s2(6);
	s2.push(2);
	s2.push(3);
	ASSERT_TRUE(s1==s2);
}
TEST(Stack, compare_one_stack_to_itself_is_true)
{
	Stack<int> s(3);
	s.push(2);
	ASSERT_TRUE(s == s);
}
TEST(Stack, compare_two_different_stacks_is_false)
{
	Stack<int> s1(6);
	s1.push(2);
	s1.push(3);
	Stack<int> s2(6);
	s2.push(21);
	s2.push(1);
	ASSERT_FALSE(s1 == s2);
}