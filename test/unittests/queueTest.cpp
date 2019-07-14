#include "gtest/gtest.h"

#include "data/queue.hpp"

class QueueTest : public ::testing::Test 
{
	protected:
		queue* testQueue;

		void SetUp( ) override
		{
			testQueue = new queue( );
		}

		void TearDown( ) override
		{
			delete testQueue;
		}
};

TEST_F( QueueTest, Queue )
{
	EXPECT_EQ( 0, testQueue->getSize( ) );

	testQueue->push( 0 );
	testQueue->push( 1 );
	testQueue->push( 2 );
	testQueue->push( 3 );
	testQueue->push( 4 );

	EXPECT_EQ( 5, testQueue->getSize( ) );

	EXPECT_EQ( 0, testQueue->pop( ) );
	EXPECT_EQ( 1, testQueue->pop( ) );
	EXPECT_EQ( 2, testQueue->pop( ) );
	EXPECT_EQ( 3, testQueue->pop( ) );
	EXPECT_EQ( 4, testQueue->pop( ) );
	ASSERT_THROW( testQueue->pop( ), queueEmptyException );
	
	EXPECT_EQ( 0, testQueue->getSize( ) );
}
TEST_F( QueueTest, EmptyException )
{
	struct queueEmptyException ex;

	EXPECT_STREQ( "Queue Empty", ex.what( ) );
}
