#include "gtest/gtest.h"

#include "data/stack.hpp"

class StackTest : public ::testing::Test 
{
	protected:
		stack* testStack;

		void SetUp( ) override
		{
			testStack = new stack( );
		}

		void TearDown( ) override
		{
			delete testStack;
		}
};

TEST_F( StackTest, Stack )
{
	EXPECT_EQ( 0, testStack->getSize( ) );
	
	testStack->push( 0 );
	testStack->push( 1 );
	testStack->push( 2 );
	testStack->push( 3 );
	testStack->push( 4 );

	EXPECT_EQ( 5, testStack->getSize( ) );

	EXPECT_EQ( 4, testStack->pop( ) );
	EXPECT_EQ( 3, testStack->pop( ) );
	EXPECT_EQ( 2, testStack->pop( ) );
	EXPECT_EQ( 1, testStack->pop( ) );
	EXPECT_EQ( 0, testStack->pop( ) );
	ASSERT_THROW( testStack->pop( ), stackEmptyException );

	EXPECT_EQ( 0, testStack->getSize( ) );
}
TEST_F( StackTest, EmptyException )
{
	struct stackEmptyException ex;

	EXPECT_STREQ( "Stack Empty", ex.what( ) );
}
