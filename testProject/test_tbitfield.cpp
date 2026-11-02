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