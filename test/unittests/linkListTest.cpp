#include "gtest/gtest.h"

#include "data/linkList.hpp"

TEST( LinkListNodeTest, NodeInt )
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
TEST( LinkListNodeTest, NodeFloat )
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


class LinkListTest : public ::testing::Test 
{
	protected:
		linkList<int>* intList;

		void SetUp( ) override
		{
			intList = new linkList<int>( );
		}

		void TearDown( ) override
		{
			delete intList;
		}
};

TEST_F( LinkListTest, ListAddRemove )
{
	intList->add( 5 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	ASSERT_THROW( intList->get( 1 ), linkListOutOfRangeException );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	intList->add( 10 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 10, intList->get( 1 ) );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	intList->add( 15 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 10, intList->get( 1 ) );
	EXPECT_EQ( 15, intList->get( 2 ) );
	ASSERT_THROW( intList->get( 3 ), linkListOutOfRangeException );

	ASSERT_THROW( intList->remove( 3 ), linkListOutOfRangeException );

	EXPECT_EQ( 10, intList->remove( 1 ));
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 15, intList->get( 1 ) );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	EXPECT_EQ( 15, intList->remove( 1 ));
	EXPECT_EQ( 5, intList->get( 0 ) );
	ASSERT_THROW( intList->get( 1 ), linkListOutOfRangeException );

	EXPECT_EQ( 5, intList->remove( 0 ));
	ASSERT_THROW( intList->get( 0 ), linkListOutOfRangeException );

	ASSERT_THROW( intList->remove( 0 ), linkListOutOfRangeException );
}
TEST_F( LinkListTest, ListCreateDelete )
{
	linkList<int>* test = new linkList<int>( );
	delete test;

	test = new linkList<int>( );
	test->add( 5 );
	delete test;

	test = new linkList<int>( );
	test->add( 5 );
	test->add( 5 );
	test->add( 5 );
	delete test;
}
TEST_F( LinkListTest, OutOfRangeException )
{
	struct linkListOutOfRangeException ex;

	EXPECT_STREQ( "Linked List Out of Bounds", ex.what( ) );
}