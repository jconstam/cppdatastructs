#include "gtest/gtest.h"

#include "data/linkList.hpp"

TEST( LinkListTest, NodeInt )
{
	linkListNode<int> test( 5 );

	EXPECT_EQ( 5, test.getValue( ) );
	EXPECT_EQ( nullptr, test.getNext( ) );

	test.setValue( 10 );

	EXPECT_EQ( 10, test.getValue( ) );
	EXPECT_EQ( nullptr, test.getNext( ) );

	linkListNode<int> test2( 20, &( test ) );

	EXPECT_EQ( 20, test2.getValue( ) );
	EXPECT_EQ( &( test ), test2.getNext( ) );

	test.setNext( &( test2 ) );

	EXPECT_EQ( 10, test.getValue( ) );
	EXPECT_EQ( &( test2 ), test.getNext( ) );	
}
TEST( LinkListTest, NodeFloat )
{
	linkListNode<float> test( 5.0 );

	EXPECT_FLOAT_EQ( 5.0, test.getValue( ) );
	EXPECT_EQ( nullptr, test.getNext( ) );

	test.setValue( 9.387 );

	EXPECT_FLOAT_EQ( 9.387, test.getValue( ) );
	EXPECT_EQ( nullptr, test.getNext( ) );

	linkListNode<float> test2( 283.493, &( test ) );

	EXPECT_FLOAT_EQ( 283.493, test2.getValue( ) );
	EXPECT_EQ( &( test ), test2.getNext( ) );

	test.setNext( &( test2 ) );

	EXPECT_FLOAT_EQ( 9.387, test.getValue( ) );
	EXPECT_EQ( &( test2 ), test.getNext( ) );	
}