#include "gtest/gtest.h"

#include "data/linkList.hpp"

TEST( LinkListNodeTest, NodeInt )
{
	linkListNode test( 5 );

	EXPECT_EQ( 5, test.getValue( ) );
	EXPECT_EQ( nullptr, test.getNext( ) );

	test.setValue( 10 );

	EXPECT_EQ( 10, test.getValue( ) );
	EXPECT_EQ( nullptr, test.getNext( ) );

	linkListNode test2( 20, &( test ) );

	EXPECT_EQ( 20, test2.getValue( ) );
	EXPECT_EQ( &( test ), test2.getNext( ) );

	test.setNext( &( test2 ) );

	EXPECT_EQ( 10, test.getValue( ) );
	EXPECT_EQ( &( test2 ), test.getNext( ) );	
}

class LinkListTest : public ::testing::Test 
{
	protected:
		linkList* intList;

		void SetUp( ) override
		{
			intList = new linkList( );
		}

		void TearDown( ) override
		{
			delete intList;
		}
};

TEST_F( LinkListTest, ListAddRemove )
{
	EXPECT_EQ( 0, intList->getSize( ) );
	intList->append( 5 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 1, intList->getSize( ) );
	ASSERT_THROW( intList->get( 1 ), linkListOutOfRangeException );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	intList->append( 10 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 10, intList->get( 1 ) );
	EXPECT_EQ( 2, intList->getSize( ) );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	intList->append( 15 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 10, intList->get( 1 ) );
	EXPECT_EQ( 15, intList->get( 2 ) );
	EXPECT_EQ( 3, intList->getSize( ) );
	ASSERT_THROW( intList->get( 3 ), linkListOutOfRangeException );

	ASSERT_THROW( intList->remove( 3 ), linkListOutOfRangeException );

	EXPECT_EQ( 10, intList->remove( 1 ));
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 15, intList->get( 1 ) );
	EXPECT_EQ( 2, intList->getSize( ) );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	EXPECT_EQ( 15, intList->remove( 1 ));
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 1, intList->getSize( ) );
	ASSERT_THROW( intList->get( 1 ), linkListOutOfRangeException );

	EXPECT_EQ( 5, intList->remove( 0 ));
	EXPECT_EQ( 0, intList->getSize( ) );
	ASSERT_THROW( intList->get( 0 ), linkListOutOfRangeException );

	ASSERT_THROW( intList->remove( 0 ), linkListOutOfRangeException );
}
TEST_F( LinkListTest, ListInsert )
{
	EXPECT_EQ( 0, intList->getSize( ) );
	ASSERT_THROW( intList->get( 0 ), linkListOutOfRangeException );
	ASSERT_THROW( intList->insert( 5, 1 ), linkListOutOfRangeException );

	intList->insert( 5, 0 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 1, intList->getSize( ) );

	intList->insert( 10, 0 );
	EXPECT_EQ( 10, intList->get( 0 ) );
	EXPECT_EQ( 5, intList->get( 1 ) );
	EXPECT_EQ( 2, intList->getSize( ) );

	intList->insert( 15, 1 );
	EXPECT_EQ( 10, intList->get( 0 ) );
	EXPECT_EQ( 15, intList->get( 1 ) );
	EXPECT_EQ( 5, intList->get( 2 ) );
	EXPECT_EQ( 3, intList->getSize( ) );
	ASSERT_THROW( intList->insert( 5, 4 ), linkListOutOfRangeException );
}
TEST_F( LinkListTest, ListPrepend )
{
	EXPECT_EQ( 0, intList->getSize( ) );
	ASSERT_THROW( intList->get( 0 ), linkListOutOfRangeException );

	intList->prepend( 5 );
	EXPECT_EQ( 5, intList->get( 0 ) );
	EXPECT_EQ( 1, intList->getSize( ) );
	ASSERT_THROW( intList->get( 1 ), linkListOutOfRangeException );

	intList->prepend( 10 );
	EXPECT_EQ( 10, intList->get( 0 ) );
	EXPECT_EQ( 5, intList->get( 1 ) );
	EXPECT_EQ( 2, intList->getSize( ) );
	ASSERT_THROW( intList->get( 2 ), linkListOutOfRangeException );

	intList->prepend( 15 );
	EXPECT_EQ( 15, intList->get( 0 ) );
	EXPECT_EQ( 10, intList->get( 1 ) );
	EXPECT_EQ( 5, intList->get( 2 ) );
	EXPECT_EQ( 3, intList->getSize( ) );
	ASSERT_THROW( intList->get( 3 ), linkListOutOfRangeException );
}
TEST_F( LinkListTest, ListCreateDelete )
{
	linkList* test = new linkList( );
	delete test;

	test = new linkList( );
	test->append( 5 );
	delete test;

	test = new linkList( );
	test->append( 5 );
	test->append( 5 );
	test->append( 5 );
	delete test;
}
TEST_F( LinkListTest, OutOfRangeException )
{
	struct linkListOutOfRangeException ex;

	EXPECT_STREQ( "Linked List Out of Bounds", ex.what( ) );
}